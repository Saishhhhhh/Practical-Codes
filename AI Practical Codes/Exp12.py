# Implement Greedy search algorithm for any of the following application:
#  Selection Sort
#  Prim's Minimal Spanning Tree Algorithm
#  Kruskal's Minimal Spanning Tree Algorithm

def selection_sort(arr):
    n = len(arr)
    for i in range(n):
        min_idx = i
        for j in range(i+1, n):
            if arr[j] < arr[min_idx]:
                min_idx = j
        arr[i], arr[min_idx] = arr[min_idx], arr[i]
    print("Sorted array:", arr)

def prim_mst(graph):
    n = len(graph)
    selected = [False] * n
    selected[0] = True
    edges = 0
    mst_weight = 0
    print("Edge : Weight")
    while edges < n - 1:
        minimum = float('inf')
        x = 0
        y = 0
        for i in range(n):
            if selected[i]:
                for j in range(n):
                    if not selected[j] and graph[i][j]:
                        if minimum > graph[i][j]:
                            minimum = graph[i][j]
                            x = i
                            y = j
        print(f"{x} - {y} : {minimum}")
        mst_weight += minimum
        selected[y] = True
        edges += 1
    print("Total weight of MST:", mst_weight)

def find_parent(parent, i):
    while parent[i] != i:
        i = parent[i]
    return i
def union(parent, rank, x, y):
    xroot = find_parent(parent, x)
    yroot = find_parent(parent, y)
    if rank[xroot] < rank[yroot]:
        parent[xroot] = yroot
    elif rank[yroot] < rank[xroot]:
        parent[yroot] = xroot
    else:
        parent[yroot] = xroot
        rank[xroot] += 1
def kruskal_mst(graph):
    n = len(graph)
    edges = []
    for i in range(n):
        for j in range(i, n):
            if graph[i][j] != 0:
                edges.append((graph[i][j], i, j))
    edges.sort()
    parent = [i for i in range(n)]
    rank = [0] * n
    mst_weight = 0
    mst_edges = []
    for edge in edges:
        w, u, v = edge
        x = find_parent(parent, u)
        y = find_parent(parent, v)
        if x != y:
            mst_edges.append((u, v, w))
            mst_weight += w
            union(parent, rank, x, y)
    print("Edges in MST:")
    for u, v, w in mst_edges:
        print(f"{u} - {v} : {w}")
    print("Total weight of MST:", mst_weight)
    
def main():
    while True:
        print("\n=== Menu ===")
        print("1. Selection Sort")
        print("2. Prim's MST Algorithm")
        print("3. Kruskal's MST Algorithm")
        print("4. Exit")
        choice = input("Enter your choice: ")
        if choice == '1':
            arr = list(map(int, input("Enter numbers separated by space: ").split()))
            selection_sort(arr)
        elif choice == '2':
            n = int(input("Enter number of vertices: "))
            print("Enter adjacency matrix row by row (0 for no edge):")
            graph = []
            for _ in range(n):
                row = list(map(int, input().split()))
                if len(row) != n:
                    print("Invalid row length.")
                    break
                graph.append(row)
            else:
                prim_mst(graph)
        elif choice == '3':
            n = int(input("Enter number of vertices: "))
            print("Enter adjacency matrix row by row (0 for no edge):")
            graph = []
            for _ in range(n):
                row = list(map(int, input().split()))
                if len(row) != n:
                    print("Invalid row length.")
                    break
                graph.append(row)
            else:
                kruskal_mst(graph)
        elif choice == '4':
            print("Exiting...")
            break
        else:
            print("Invalid choice. Try again.")
if __name__ == "__main__":
    main()


# Enter your choice: 1
# Enter numbers separated by space: 2 1 6 4 3 8
# Sorted array: [1, 2, 3, 4, 6, 8]

# Enter your choice: 2
# Enter number of vertices: 4
# Enter adjacency matrix row by row (0 for no edge):
# 0 2 0 6
# 2 0 3 8
# 0 3 0 0
# 6 8 0 0

# Enter your choice: 3
# Enter number of vertices: 4
# Enter adjacency matrix row by row (0 for no edge):
# 0 2 0 6
# 2 0 3 8
# 0 3 0 0
# 6 8 0 0

# Selection Sort
# Time Complexity O(n²)
# Space Complexity: O(1)

# Prim’s 
# Time Complexity: O(V²)
# Space Complexity	O(V)	

# Kruskal’s	
# Time Complexity: O(E log E)	
# Space Complexity	O(V)

# https://chatgpt.com/share/6914d579-a354-8002-887e-6504c0d91d90