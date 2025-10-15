from collections import deque

def dfs(vertex, visited, graph):
    visited.add(vertex)
    print(vertex, end=' ')
    for neighbor in graph.get(vertex, []):
        if neighbor not in visited:
            dfs(neighbor, visited, graph)

def bfs(start, graph):
    visited = set([start])
    queue = deque([start])
    while queue:
        v = queue.popleft()
        print(v, end=' ')
        for neighbor in graph.get(v, []):
            if neighbor not in visited:
                visited.add(neighbor)
                queue.append(neighbor)

def menu():
    print("\n===== Graph Traversal Menu =====")
    print("1. Depth First Search (DFS)")
    print("2. Breadth First Search (BFS)")
    print("3. Exit")
    print("================================")

if __name__ == "__main__":
    graph = {}
    n = int(input("Enter number of edges: "))

    for _ in range(n):
        u, v = input("Edge (u v): ").split()
        graph.setdefault(u, []).append(v)
        graph.setdefault(v, []).append(u)

    start = input("Enter start vertex: ").strip()

    if start not in graph:
        print("Start vertex not found in graph.")
    else:
        while True:
            menu()
            choice = input("Enter your choice (1-3): ")

            if choice == '1':
                print("\nDFS Traversal:")
                dfs(start, set(), graph)
                print()
            elif choice == '2':
                print("\nBFS Traversal:")
                bfs(start, graph)
                print()
            elif choice == '3':
                print("Exiting program. Goodbye!")
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
