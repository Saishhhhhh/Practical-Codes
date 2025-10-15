import json
import sys
from copy import deepcopy

INFINITY = 10**9

def load_topology(path):
    with open(path, "r") as f:
        topo = json.load(f)
    nodes = topo["nodes"]
    edges = topo["links"]
    graph = {n: {} for n in nodes}
    for u, v, w in edges:
        graph[u][v] = w
        graph[v][u] = w
    return nodes, graph

def initialize_tables(nodes, graph):
    # distance vector tables: dist[node][dest] = cost, next_hop[node][dest] = next-hop
    dist = {n: {m: INFINITY for m in nodes} for n in nodes}
    next_hop = {n: {m: None for m in nodes} for n in nodes}
    for n in nodes:
        dist[n][n] = 0
    for u in nodes:
        for v, w in graph[u].items():
            dist[u][v] = w
            next_hop[u][v] = v
    return dist, next_hop

def simulate_distance_vector(nodes, graph, max_rounds=100):
    dist, next_hop = initialize_tables(nodes, graph)
    round_no = 0
    while True:
        changed = False
        round_no += 1
        # simulate each node sending its vector to neighbors and neighbors updating
        for u in nodes:
            # u sends its dist[u] to all neighbors
            for neighbor in graph[u]:
                # neighbor updates its table using u's vector
                for dest in nodes:
                    via_u_cost = dist[u][dest] + graph[neighbor][u]  # cost neighbor->u + u->dest
                    if via_u_cost < dist[neighbor][dest]:
                        dist[neighbor][dest] = via_u_cost
                        next_hop[neighbor][dest] = u if next_hop[neighbor][u] is None else next_hop[neighbor][u]
                        changed = True
        if not changed or round_no >= max_rounds:
            break
    return dist, next_hop, round_no

def print_routing_tables(nodes, dist, next_hop):
    for n in nodes:
        print(f"\nRouting table for {n}")
        print(f"{'Destination':>12} {'Cost':>8} {'NextHop':>8}")
        for dest in sorted(nodes):
            cost = dist[n][dest]
            cost_str = "∞" if cost >= INFINITY else str(cost)
            nh = next_hop[n][dest] if next_hop[n][dest] is not None else "-"
            print(f"{dest:>12} {cost_str:>8} {nh:>8}")

def reconstruct_path_from_dv(source, dest, next_hop):
    if source == dest:
        return [source]
    path = [source]
    cur = source
    visited = set([cur])
    while cur != dest:
        nh = next_hop[cur][dest]
        if nh is None or nh in visited:
            return None  # no path or loop detected
        path.append(nh)
        visited.add(nh)
        cur = nh
    return path

def main():
    if len(sys.argv) < 2:
        print("Usage: python distance_vector.py topology/topology.json")
        return
    topo_file = sys.argv[1]
    nodes, graph = load_topology(topo_file)
    dist, next_hop, rounds = simulate_distance_vector(nodes, graph)
    print(f"Converged in {rounds} rounds.")
    print_routing_tables(nodes, dist, next_hop)

    # interactive path query
    while True:
        q = input("\nEnter source,destination to show path (like A D) or 'quit': ").strip()
        if q.lower() in ("q", "quit", "exit", ""):
            break
        try:
            s, d = q.split()
            if s not in nodes or d not in nodes:
                print("Unknown nodes. Try again.")
                continue
            path = reconstruct_path_from_dv(s, d, next_hop)
            if path:
                # compute cost
                cost = 0
                for i in range(len(path)-1):
                    cost += graph[path[i]][path[i+1]]
                print(f"Path {s} -> {d}: {' -> '.join(path)} (cost {cost})")
            else:
                print("No path (or loop) found according to DV tables.")
        except Exception:
            print("Invalid input. Example: A D")

if __name__ == "__main__":
    main()
