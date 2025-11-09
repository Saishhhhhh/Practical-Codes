import json
import sys
import heapq

# ------------------------------------------------------------------
# Function to load the network topology from a JSON file
# ------------------------------------------------------------------
def load_topology(file_path):
    """
    Reads a JSON file containing nodes and links, and builds a graph.
    Example JSON format:
    {
        "nodes": ["A", "B", "C"],
        "links": [["A", "B", 4], ["A", "C", 2], ["B", "C", 5]]
    }
    """
    with open(file_path, "r") as file:
        topology = json.load(file)

    nodes = topology["nodes"]
    links = topology["links"]

    # Build graph as adjacency list
    graph = {}

    for node in nodes:
        graph[node] = {}

    for src, dest, cost in links:
        # Undirected connection (both directions)
        graph[src][dest] = cost
        graph[dest][src] = cost

    return nodes, graph


# ------------------------------------------------------------------
# Dijkstra’s Algorithm - finds shortest path from a source node
# ------------------------------------------------------------------
def dijkstra(source, graph):
    # dist[node] = shortest known distance from source
    dist = {}
    parent = {}
    visited = {}

    # Initialize all nodes
    for node in graph:
        dist[node] = float('inf')   # unknown distance
        parent[node] = None        # no parent yet
        visited[node] = False      # not visited

    dist[source] = 0  # distance to itself is zero

    # Repeat for all nodes
    for _ in range(len(graph)):
        # Step 1: Pick unvisited node with smallest distance
        current_node = None
        current_dist = float('inf')

        for node in graph:
            if not visited[node] and dist[node] < current_dist:
                current_dist = dist[node]
                current_node = node

        # If no reachable node left, break
        if current_node is None:
            break

        # Mark current node as visited
        visited[current_node] = True

        # Step 2: Relax/update all neighbors
        for neighbor, weight in graph[current_node].items():
            if not visited[neighbor]:
                new_distance = dist[current_node] + weight
                if new_distance < dist[neighbor]:
                    dist[neighbor] = new_distance
                    parent[neighbor] = current_node

    return dist, parent



# ------------------------------------------------------------------
# Function to reconstruct the path from source to destination
# ------------------------------------------------------------------
def reconstruct_path(parent, src, dst):
    """
    Builds the shortest path from source to destination
    using the parent dictionary.
    """
    if src == dst:
        return [src]
    if parent[dst] is None:
        return None  # No path found

    path = []
    current = dst
    while current is not None:
        path.append(current)
        if current == src:
            break
        current = parent[current]

    path.reverse()
    if path[0] != src:
        return None
    return path


# ------------------------------------------------------------------
# Get the next hop (first step) from the full path
# ------------------------------------------------------------------
def next_hop_from_path(path):
    """
    Returns the next hop (second node) from a path list.
    Example: A -> B -> C -> D  => next hop from A = B
    """
    if not path or len(path) < 2:
        return None
    return path[1]


# ------------------------------------------------------------------
# Build routing table for a given node
# ------------------------------------------------------------------
def build_routing_table(node, graph):
    """
    Builds a routing table for one node.
    Each entry: destination -> (cost, next hop)
    """
    dist, parent = dijkstra(node, graph)
    table = {}

    for dest in graph:
        if dest == node:
            table[dest] = (0, "-")  # cost 0 to self
        else:
            path = reconstruct_path(parent, node, dest)
            if path is None:
                table[dest] = (float('inf'), None)  # unreachable
            else:
                nh = next_hop_from_path(path)
                table[dest] = (dist[dest], nh)

    return table


# ------------------------------------------------------------------
# Print routing table in a readable format
# ------------------------------------------------------------------
def print_table(node, table):
    """
    Nicely prints the routing table of one node.
    """
    print(f"\nRouting Table for Node {node}")
    print("-" * 40)
    print(f"{'Destination':<12} {'Cost':<8} {'Next Hop':<10}")
    print("-" * 40)

    for dest in sorted(table):
        cost, nh = table[dest]
        cost_str = "∞" if cost == float('inf') else str(cost)
        nh_str = "-" if nh is None else nh
        print(f"{dest:<12} {cost_str:<8} {nh_str:<10}")

    print("-" * 40)


# ------------------------------------------------------------------
# MAIN FUNCTION
# ------------------------------------------------------------------
def main():
    if len(sys.argv) < 2:
        print("Usage: python link_state.py topology/topology.json")
        return

    topo_file = sys.argv[1]

    # Load the network topology from JSON
    nodes, graph = load_topology(topo_file)

    # Build and print routing tables for all nodes
    for node in nodes:
        routing_table = build_routing_table(node, graph)
        print_table(node, routing_table)

    # Optional: allow user to query paths
    while True:
        query = input("\nEnter 'source destination' (e.g., A D) or 'quit' to exit: ").strip()
        if query.lower() in ("q", "quit", "exit", ""):
            break

        try:
            src, dst = query.split()
            if src not in graph or dst not in graph:
                print("⚠️  Unknown nodes! Please try again.")
                continue

            _, parent = dijkstra(src, graph)
            path = reconstruct_path(parent, src, dst)

            if path:
                total_cost = sum(graph[path[i]][path[i + 1]] for i in range(len(path) - 1))
                print(f"Shortest Path {src} -> {dst}: {' -> '.join(path)} (Cost = {total_cost})")
            else:
                print("No path found between those nodes.")

        except ValueError:
            print("⚠️  Invalid input! Example: A D")


# ------------------------------------------------------------------
# Entry point
# ------------------------------------------------------------------
if __name__ == "__main__":
    main()
