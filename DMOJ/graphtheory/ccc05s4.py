import sys
from collections import defaultdict
input = sys.stdin.readline
t = int(input())
for _ in range(t):
    n = int(input())

    graph = defaultdict(list)

    a = input()[:-1]
    for _ in range(n - 1):
        b = input()[:-1]

        graph[b].append(a)
        a = b

    def dfs(node, past, time):
        maxTime = time

        for e in graph[node]:
            if e != past:
                maxTime = max(dfs(e, node, time + 20), maxTime)

        return maxTime

    print((n * 10) - dfs(a, -1, 0))
