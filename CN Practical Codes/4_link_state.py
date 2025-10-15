import json
import sys
import heapq
from collections import defaultdict

def load_topology(path):
    with open(path, "r") as f:
        topo = json.load(f)
    nodes = topo["nodes"]
    edges = topo["links"]
    graph = {n: {} for n in nodes}
    for u, v, w in edges:
        graph[u][v] = w
        graph[v][u] = w  # undirected
    return nodes, graph

def dijkstra(source, graph):
    # returns dist dict and parent dict (for path reconstruction)
    dist = {n: float('inf') for n in graph}
    parent = {n: None for n in graph}
    dist[source] = 0
    pq = [(0, source)]
    while pq:
        d, u = heapq.heappop(pq)
        if d > dist[u]:
            continue
        for v, w in graph[u].items():
            nd = d + w
            if nd < dist[v]:
                dist[v] = nd
                parent[v] = u
                heapq.heappush(pq, (nd, v))
    return dist, parent

def reconstruct_path(parent, src, dst):
    if parent[dst] is None and src != dst:
        if src == dst:
            return [src]
        return None
    path = []
    cur = dst
    while cur is not None:
        path.append(cur)
        if cur == src:
            break
        cur = parent[cur]
    path.reverse()
    if path[0] != src:
        return None
    return path

def next_hop_from_path(path):
    if not path or len(path) < 2:
        return None
    return path[1]

def build_routing_table(node, graph):
    dist, parent = dijkstra(node, graph)
    table = {}
    for dest in graph:
        if dest == node:
            table[dest] = (0, "-")
        else:
            path = reconstruct_path(parent, node, dest)
            if path is None:
                table[dest] = (float('inf'), None)
            else:
                nh = next_hop_from_path(path)
                table[dest] = (dist[dest], nh)
    return table

def print_table(node, table):
    print(f"\nRouting table for {node}")
    print(f"{'Destination':>12} {'Cost':>8} {'NextHop':>8}")
    for dest in sorted(table):
        cost, nh = table[dest]
        cost_str = "∞" if cost == float('inf') else str(cost)
        nh_str = "-" if nh is None else nh
        print(f"{dest:>12} {cost_str:>8} {nh_str:>8}")

def main():
    if len(sys.argv) < 2:
        print("Usage: python link_state.py topology/topology.json")
        return
    topo_file = sys.argv[1]
    nodes, graph = load_topology(topo_file)
    for n in nodes:
        table = build_routing_table(n, graph)
        print_table(n, table)

    # optionally allow path queries
    while True:
        q = input("\nEnter source,destination to show path (like A D) or 'quit': ").strip()
        if q.lower() in ("q", "quit", "exit", ""):
            break
        try:
            s, d = q.split()
            if s not in graph or d not in graph:
                print("Unknown nodes. Try again.")
                continue
            _, parent = dijkstra(s, graph)
            path = reconstruct_path(parent, s, d)
            if path:
                print(f"Path {s} -> {d}: {' -> '.join(path)} (cost {sum(graph[path[i]][path[i+1]] for i in range(len(path)-1))})")
            else:
                print("No path found.")
        except Exception as e:
            print("Invalid input. Example: A D")

if __name__ == "__main__":
    main()
