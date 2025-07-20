from collections import defaultdict

graph = defaultdict(list)

roads = []
letters = list("ABCDEFGHIJKLMNOPQRSTUVWXYZ")

while True:
    i = input()
    if i == "**": break

    roads.append((letters.index(i[0]), letters.index(i[1])))
    graph[letters.index(i[0])].append(letters.index(i[1]))
    graph[letters.index(i[1])].append(letters.index(i[0]))

count = 0

def dfs(node, past):
    if visited[node]:
        return 0

    nVisited = 1
    visited[node] = True
    for n in graph[node]:
        if n != past:
            nVisited += dfs(n, node)

    return nVisited

for p1, p2 in roads:
    visited = [False for _ in range(26)]
    graph[p1].pop(graph[p1].index(p2))
    graph[p2].pop(graph[p2].index(p1))
    # print(f"{n} from {letters[p1] + letters[p2]}")
    if dfs(p1, -1) != len(graph.keys()):
        count += 1
        print(letters[p1] + letters[p2])

    graph[p1].append(p2)
    graph[p2].append(p1)

print(f"There are {count} disconnecting roads.")
