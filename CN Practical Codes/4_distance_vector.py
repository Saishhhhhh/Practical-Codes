import json
import sys

# A very large number to represent infinity (no direct connection)
INFINITY = 10**9


# ------------------------------------------
# Step 1: Load the network topology from JSON file
# ------------------------------------------
def load_topology(path):
    # Open and read the JSON file
    with open(path, "r") as f:
        topo = json.load(f)

    # Extract the node (router) names and link information
    nodes = topo["nodes"]
    edges = topo["links"]

    # Create an empty graph structure
    graph = {}
    for n in nodes:
        graph[n] = {}

    # Fill in the connection details (both directions, since undirected)
    for link in edges:
        u, v, w = link  # u = source, v = destination, w = cost
        graph[u][v] = w
        graph[v][u] = w

    return nodes, graph


# ------------------------------------------
# Step 2: Initialize distance and next-hop tables
# ------------------------------------------
def initialize_tables(nodes, graph):
    # Create two tables:
    # dist[node][dest] = cost
    # next_hop[node][dest] = next router to reach destination

    dist = {}
    next_hop = {}

    # Initialize all distances to INFINITY and next hops to None
    for n in nodes:
        dist[n] = {}
        next_hop[n] = {}
        for m in nodes:
            dist[n][m] = INFINITY
            next_hop[n][m] = None

    # Distance to itself = 0
    for n in nodes:
        dist[n][n] = 0

    # For directly connected neighbors, use their link cost
    for u in nodes:
        for v in graph[u]:
            dist[u][v] = graph[u][v]
            next_hop[u][v] = v

    return dist, next_hop


# ------------------------------------------
# Step 3: Simulate the Distance Vector Routing Process
# ------------------------------------------
def simulate_distance_vector(nodes, graph, max_rounds=100):
    dist, next_hop = initialize_tables(nodes, graph)
    round_no = 0

    # Keep updating routing tables until no more changes
    while True:
        changed = False
        round_no += 1

        # Each router sends its table to all neighbors
        for u in nodes:
            for neighbor in graph[u]:
                # Each neighbor updates its own table using info from u
                for dest in nodes:
                    # cost(neighbor -> dest) = cost(neighbor -> u) + cost(u -> dest)
                    via_u_cost = dist[u][dest] + graph[neighbor][u]

                    # If this new path is cheaper, update neighbor's table
                    if via_u_cost < dist[neighbor][dest]:
                        dist[neighbor][dest] = via_u_cost

                        # Set next hop for the neighbor
                        if next_hop[neighbor][u] is None:
                            next_hop[neighbor][dest] = u
                        else:
                            next_hop[neighbor][dest] = next_hop[neighbor][u]

                        changed = True

        # Stop if no changes or maximum rounds reached
        if not changed or round_no >= max_rounds:
            break

    return dist, next_hop, round_no


# ------------------------------------------
# Step 4: Print the Routing Tables
# ------------------------------------------
def print_routing_tables(nodes, distance_table, next_hop_table):
    """
    Prints the routing table for each node in the network.
    """

    # Loop through every node to print its routing table
    for node in nodes:
        print("\nRouting Table for", node)
        print("Destination    Cost    Next Hop")
        print("--------------------------------")

        # Loop through all possible destinations
        for destination in sorted(nodes):
            cost = distance_table[node][destination]  # cost to reach destination
            next_hop = next_hop_table[node][destination]  # next hop to reach destination

            # If cost is very large, show infinity symbol
            if cost >= INFINITY:
                cost_display = "∞"
            else:
                cost_display = str(cost)

            # If there is no next hop, display a dash
            if next_hop is None:
                next_hop = "-"

            # Print destination, cost, and next hop in simple format
            print(f"{destination:12} {cost_display:8} {next_hop:8}")

        print("--------------------------------")


# ------------------------------------------
# Step 5: Reconstruct Path between Source and Destination
# ------------------------------------------
def reconstruct_path_from_dv(source, dest, next_hop):
    # If source and destination are same
    if source == dest:
        return [source]

    path = [source]
    current = source
    visited = set([current])

    # Follow next hops until we reach destination
    while current != dest:
        nh = next_hop[current][dest]
        if nh is None or nh in visited:
            return None  # no path or loop detected
        path.append(nh)
        visited.add(nh)
        current = nh

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
