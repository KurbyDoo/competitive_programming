from collections import defaultdict
n, m, a, b = map(int, input().split())
graph = defaultdict(list)
visited = [False for _ in range(n + 1)]

for _ in range(m):
    x, y = map(int, input().split())

    graph[x].append(y)
    graph[y].append(x)


def dfs(node):
    if node == b:
        return True

    visited[node] = True
    for e in graph[node]:
        if not visited[e]:
            if dfs(e):
                return True
            
    return False

print("GO SHAHIR!" if dfs(a) else "NO SHAHIR!")
