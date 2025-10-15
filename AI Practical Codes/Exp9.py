from queue import PriorityQueue
n = int(input("Number of edges: "))
graph = {}

for _ in range(n):
    u, v, cost = input("Edge (u v cost): ").split()
    cost = float(cost)
    graph.setdefault(u, []).append((v, cost))
    graph.setdefault(v, []).append((u, cost))  # undirected

h = {}
m = int(input("Number of heuristic values: "))
print("Enter heuristic (node value):")
for _ in range(m):
    node, val = input().split()
    h[node] = float(val)

start = input("Start node: ")
goal = input("Goal node: ")

def a_star(graph, start, goal, h):
    open_set = PriorityQueue()
    open_set.put((0, start))
    came_from = {}
    g_score = {node: float('inf') for node in graph}
    g_score[start] = 0
    f_score = {node: float('inf') for node in graph}
    f_score[start] = h.get(start, 0)

    while not open_set.empty():
        current = open_set.get()[1]

        if current == goal:
            path = []
            while current in came_from:
                path.append(current)
                current = came_from[current]
            path.append(start)
            return path[::-1]

        for neighbor, cost in graph.get(current, []):
            tentative_g = g_score[current] + cost
            if tentative_g < g_score.get(neighbor, float('inf')):
                came_from[neighbor] = current
                g_score[neighbor] = tentative_g
                f_score[neighbor] = tentative_g + h.get(neighbor, 0)
                open_set.put((f_score[neighbor], neighbor))
    return None

path = a_star(graph, start, goal, h)
if path:
    print("Path:", " -> ".join(path))
else:
    print("No path found")

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
