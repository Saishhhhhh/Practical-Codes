# Implement depth first search algorithm and Breadth First Search
# algorithm. Use an undirected graph and develop a recursive
# algorithm for searching all the vertices of a graph or tree data
# structure.

from collections import deque  # Helps create a queue for BFS

# ---------- DEPTH FIRST SEARCH (DFS) ----------
def dfs(vertex, visited, graph):

    visited.add(vertex)
    print(vertex, end=' ')

    # Go through all the neighbors of the current vertex
    for neighbor in graph.get(vertex, []):
        if neighbor not in visited:
            dfs(neighbor, visited, graph)  # Recursive call


# ---------- BREADTH FIRST SEARCH (BFS) ----------
def bfs(start, graph):

    visited = set([start])   # Keep track of visited vertices
    queue = deque([start])   # Queue for BFS

    while queue:
        vertex = queue.popleft()  # Take vertex from the front
        print(vertex, end=' ')

        # Visit all unvisited neighbors
        for neighbor in graph.get(vertex, []):
            if neighbor not in visited:
                visited.add(neighbor)
                queue.append(neighbor)


# ---------- MENU FUNCTION ----------
def menu():
    print("\n===== Graph Traversal Menu =====")
    print("1. Depth First Search (DFS)")
    print("2. Breadth First Search (BFS)")
    print("3. Exit")
    print("================================")


# ---------- MAIN LOGIC ----------
graph = {}  # Empty graph dictionary

# Take user input for number of edges
n = int(input("Enter number of edges: "))

# Get all edges (u, v)
for i in range(n):
    u, v = input(f"Enter edge {i+1} (u v): ").split()

    # Since the graph is undirected, connect both ways
    if u not in graph:
        graph[u] = []
    if v not in graph:
        graph[v] = []

    graph[u].append(v)
    graph[v].append(u)

# Get starting vertex
start = input("Enter start vertex: ").strip()

# Check if vertex exists
if start not in graph:
    print("Error: Start vertex not found in the graph!")
else:
    while True:
        menu()
        choice = input("Enter your choice (1-3): ")

        if choice == '1':
            print("\nDFS Traversal Order:")
            dfs(start, set(), graph)
            print()
        elif choice == '2':
            print("\nBFS Traversal Order:")
            bfs(start, graph)
            print()
        elif choice == '3':
            print("Exiting program. Goodbye! 👋")
            break
        else:
            print("Invalid choice! Please enter 1, 2, or 3.")

# Enter number of edges: 6
# Edge (u v): A B
# Edge (u v): A C
# Edge (u v): B D
# Edge (u v): B E
# Edge (u v): C F
# Edge (u v): E F
# Enter start vertex: A

# Space Complexity (DFS) : O(V) V is number of vertices
# Time Complexity (DFS) : O(V + E) E is number of edges

# Space Complexity (BFS) :  O(V)
# Time Complexity (BFS) : O(V + E)

# https://chatgpt.com/share/691488bc-eb18-8002-9f94-7f831bf5691c