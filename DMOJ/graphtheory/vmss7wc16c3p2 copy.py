from collections import defaultdict
import sys

n, m, a, b = map(int, input().split())
graph = defaultdict(list)
for i in range(m):
    x, y = map(int, input().split())
    graph[x].append(y)
    graph[y].append(x)

visited = [False for _ in range(n + 1)]


def dfs(node, end):
    if node == end:
        print("GO SHAHIR!")
        sys.exit()

    visited[node] = True
    for neighbour in graph[node]:
        if visited[neighbour] == False:
            dfs(neighbour, end)


dfs(a, b)
print("NO SHAHIR!")