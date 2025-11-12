# Implement A star (A*) Algorithm for any game search problem.

# ===============================================
# A* Search Algorithm (Beginner Friendly Version)
# ===============================================

from queue import PriorityQueue  # Used to get the node with the lowest cost

# ---------- Step 1: Input Graph ----------
graph = {}  # Dictionary to store the graph

# Number of edges
n = int(input("Enter number of edges: "))

# Take each edge input
for i in range(n):
    u, v, cost = input(f"Enter edge {i+1} (u v cost): ").split()
    cost = float(cost)  # Convert cost to a number

    # Add the edge to the graph (since it's undirected, add both ways)
    if u not in graph:
        graph[u] = []
    if v not in graph:
        graph[v] = []
    graph[u].append((v, cost))
    graph[v].append((u, cost))

# ---------- Step 2: Input Heuristic Values ----------
h = {}  # Heuristic dictionary
m = int(input("Enter number of heuristic values: "))

print("Enter heuristic values in format: node value")
for i in range(m):
    node, val = input(f"Heuristic {i+1}: ").split()
    h[node] = float(val)

# ---------- Step 3: Input Start and Goal ----------
start = input("Enter start node: ").strip()
goal = input("Enter goal node: ").strip()


# ---------- Step 4: Define A* Search Function ----------
def a_star(graph, start, goal, h):
    open_set = PriorityQueue()
    open_set.put((0, start))
    came_from = {}
    g_score = {start: 0}

    while not open_set.empty():
        current = open_set.get()[1]
        if current == goal:
            path = [goal]
            while current in came_from:
                current = came_from[current]
                path.append(current)
            return path[::-1]

        for neighbor, cost in graph.get(current, []):
            new_cost = g_score[current] + cost
            if new_cost < g_score.get(neighbor, float('inf')):
                came_from[neighbor] = current
                g_score[neighbor] = new_cost
                priority = new_cost + h.get(neighbor, 0)
                open_set.put((priority, neighbor))

    return None

# ---------- Step 6: Run A* and Show Result ----------
path = a_star(graph, start, goal, h)

if path:
    print("\nShortest Path Found:")
    print(" -> ".join(path))
else:
    print("\nNo path found between", start, "and", goal)


# Number of edges: 8
# Edge (u v cost): A B 1
# Edge (u v cost): A C 3
# Edge (u v cost): B D 3
# Edge (u v cost): B E 6
# Edge (u v cost): C F 4
# Edge (u v cost): D G 4
# Edge (u v cost): E G 2
# Edge (u v cost): F G 5
# Number of heuristic values: 7
# Enter heuristic (node value):
# A 7
# B 6
# C 5
# D 3
# E 2
# F 1
# G 0
# Start node: A
# Goal node: G

# Space Complexity  :   O(B^D)
# Time Complexity  : O(B^D), where B is the branching factor of the search tree and D is the depth of the optimal solution.

# https://chatgpt.com/share/69149f42-56d8-8002-8565-48dd056e127c