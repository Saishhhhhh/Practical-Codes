def dijkstra(graph, start_vertex):
    V = len(graph)  # Total number of vertices
    visited = [False] * V  # Keep track of visited vertices
    distance = [float('inf')] * V  # Set all distances to infinity
    distance[start_vertex] = 0  # Distance to start vertex is 0

    for _ in range(V):
        # Step 1: Pick the unvisited vertex with the smallest distance
        min_dist = float('inf')
        min_index = -1

        for i in range(V):
            if not visited[i] and distance[i] < min_dist:
                min_dist = distance[i]
                min_index = i

        if min_index == -1:
            break  # Remaining vertices are unreachable

        u = min_index
        visited[u] = True

        # Step 2: Update distances to adjacent vertices
        for v in range(V):
            if graph[u][v] != 0 and not visited[v]:
                new_distance = distance[u] + graph[u][v]
                if new_distance < distance[v]:
                    distance[v] = new_distance

    # Step 3: Print shortest distances
    print(f"\nShortest distances from vertex {start_vertex}:")
    for i in range(V):
        if distance[i] == float('inf'):
            print(f"To vertex {i}: ∞")
        else:
            print(f"To vertex {i}: {distance[i]}")


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


# Run the program
menu()
