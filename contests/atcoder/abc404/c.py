from collections import defaultdict
import sys
sys.setrecursionlimit(300000)
n, m = map(int, input().split())
graph = defaultdict(list)
degree = [0] * (n + 1)
unq = set()
cycle = True
for _ in range(m):
    a, b = map(int, input().split())
    degree[a] += 1
    degree[b] += 1
    graph[a].append(b)
    graph[b].append(a)
    if a == b:
        cycle = False
    if b < a:
        a, b = b, a
    unq.add((a, b))

if len(unq) != n:
    cycle = False

for i in range(n):
    if degree[i + 1] != 2:
        cycle = False

visited = [False] * (n + 1)
def dfs(node):
    count = 1
    for e in graph[node]:
        if visited[e]: continue
        visited[e] = True
        count += dfs(e)
    return count
visited[1] = True
sz = dfs(1)
if sz != n:
    cycle = False
print("Yes" if cycle else "No")
