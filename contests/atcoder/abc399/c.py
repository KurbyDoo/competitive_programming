from collections import defaultdict
import sys
sys.setrecursionlimit(200010)
n, m = map(int, input().split())
graph = defaultdict(list)
visited = [False] * (n + 1)
ans = m
for i in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

def dfs(node, past):
    size = 1
    for e in graph[node]:
        if e == past or visited[e]:
            continue
        visited[e] = True
        size += dfs(e, node)

    return size

for i in range(1, n + 1):
    if visited[i]:
        continue
    
    visited[i] = True
    ans -= dfs(i, -1) - 1

print(ans)