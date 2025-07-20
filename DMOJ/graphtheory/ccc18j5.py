import sys
from collections import defaultdict, deque
input = sys.stdin.readline

n = int(input())

visited = [False for _ in range(n + 1)]

graph = defaultdict(list)
for i in range(1, n + 1):
    amount, *nums = map(int, input().split())
    # print(amount, nums)
    for j in range(amount):
        graph[i].append(nums[j])

minDist = 999999
q = deque([(1, 1)])
visited[1] = True
while q:
    curNode, curDist = q.popleft()

    if len(graph[curNode]) == 0:
        minDist = min(minDist, curDist)

    for e in graph[curNode]:
        if visited[e]: continue

        visited[e] = True
        q.append((e, curDist + 1))

# print(visited)
print("Y" if sum(visited) == n else "N")
print(minDist)

