import sys

def dijkstra(graph, start_vertex):
    V = len(graph)
    visited = [False] * V
    distance = [sys.maxsize] * V
    distance[start_vertex] = 0

    for _ in range(V):
        min_dist = sys.maxsize
        min_index = -1

        # Find vertex with minimum distance not yet visited
        for i in range(V):
            if not visited[i] and distance[i] < min_dist:
                min_dist = distance[i]
                min_index = i

        if min_index == -1:
            break  # All remaining vertices are unreachable

        u = min_index
        visited[u] = True

        # Update distances of adjacent vertices
        for v in range(V):
            if graph[u][v] != 0 and not visited[v]:
                if distance[v] > distance[u] + graph[u][v]:
                    distance[v] = distance[u] + graph[u][v]

    print(f"\nShortest distances from vertex {start_vertex}:")
    for i in range(V):
        print(f"To vertex {i}: {distance[i] if distance[i] != sys.maxsize else '∞'}")


def menu():
    while True:
        print("\n======= MENU =======")
        print("1. Dijkstra's Shortest Path Algorithm")
        print("2. Exit")

        choice = input("Enter your choice (1-2): ")

        if choice == '1':
            V = int(input("Enter number of vertices: "))
            graph = []

            print("Enter the adjacency matrix (0 for no edge):")
            for i in range(V):
                row = []
                for j in range(V):
                    weight = int(input(f"Weight from {i} to {j}: "))
                    row.append(weight)
                graph.append(row)

            start = int(input("Enter starting vertex: "))

            if start >= V:
                print("Invalid start vertex.")
            else:
                dijkstra(graph, start)

        elif choice == '2':
            print("Exiting program.")
            break

        else:
            print("Invalid choice. Please enter 1 or 2.")


# Run the menu
menu()

# Enter your choice (1-2): 1
# Enter number of vertices: 3
# Enter the adjacency matrix (0 for no edge):
# Weight from 0 to 0: 0
# Weight from 0 to 1: 2
# Weight from 0 to 2: 3
# Weight from 1 to 0: 4
# Weight from 1 to 1: 6
# Weight from 1 to 2: 3
# Weight from 2 to 0: 2
# Weight from 2 to 1: 1
# Weight from 2 to 2: 3
# Enter starting vertex: 0