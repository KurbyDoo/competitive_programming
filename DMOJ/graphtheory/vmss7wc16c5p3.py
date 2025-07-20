# Author: KurbyDoo
# Creation Date: Jul 19, 2025
# Problem Link: https://dmoj.ca/problem/vmss7wc16c5p3
# Problem Name: VM7WC '16 #5 Gold - Jayden Studies Trees
# Status: Solved
# Notes:
#     Original creation date unknown
#     
#     
#     
import sys
from collections import defaultdict, deque
input = sys.stdin.readline

# with open("test.txt") as f:
#     inside = f.read().split('\n')
#     # print(inside)
#     def input():
#         return inside.pop(0)

n = int(input())

if n == 1:
    print(0)
    sys.exit()

g = defaultdict(list)

for _ in range(n - 1):
    a, b = map(int, input().split())

    g[a].append(b)
    g[b].append(a)


visited = [False for _ in range(1, n + 2)]

visited[list(g.keys())[0]] = True
q = deque([list(g.keys())[0]])

while q:
    node = q.popleft()

    for e in g[node]:
        if not visited[e]:
            visited[e] = True
            q.append(e)

maxNode = node


# print(f"{(maxNode, maxCount) = }")
# print(visited)

q = deque([[maxNode, 0]])

visited = [False for _ in range(1, n + 2)]
visited[maxNode] = True

while q:
    node, count = q.popleft()
    # print(f'checking {node}')

    # print(f"{g[node] = }")
    for e in g[node]:
        # print(f"{maxCount = }")
        if not visited[e]:
            visited[e] = True
            q.append([e, count + 1])
    
print(count)
