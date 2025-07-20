import sys
from collections import defaultdict
from collections import deque
input = sys.stdin.readline

n = int(input())

graph = defaultdict(list)

for _ in range(n):
    a, b = map(int, input().split())
    graph[a].append(b)


q = deque()
visited = [False] * (n + 1)
start, end = map(int, input().split())
tangled = False
q.append(start)

while q:
    curNode = q.popleft()
    visited[curNode] = True

    if curNode == end:
        tangled = True
        break

    for m in graph[curNode]:
        if not visited[m]:
            q.append(m)

if tangled:
    print("Tangled")

else:
    print("Not Tangled")


