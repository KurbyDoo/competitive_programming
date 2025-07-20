from collections import defaultdict, deque
import math
good = [False for _ in range(100010)]
visited1 = [False for _ in range(100010)]
visited2 = [False for _ in range(100010)]
graph = defaultdict(list)

firstDist, firstNode, secondDist, secondNode = -1, -1, -1, -1
maxDist, maxNode = 0, 0

n = int(input())
strengths = list(map(int, input().split()))
for i in range(1, len(strengths) + 1):
    strength = strengths[i - 1]
    dis = 1 + 4 * 1 * strength
    if int(math.sqrt(dis)) == math.sqrt(dis) and int(math.sqrt(dis)) % 2 == 1:
        good[i] = True

for i in range(n - 1):
    a, b = map(int, input().split())
    if good[a] and good[b]:
        graph[a].append(b)
        graph[b].append(a)

# print(*good[0:n + 1])

for i in range(1, n + 1):
    if visited1[i] or not good[i]: continue
    q = deque([(i, 1)])
    visited1[i] = True
    # print("start")
    while q:
        cn, cd = q.popleft()
        # print(f"{cd = } {cn = }")
        for e in graph[cn]:
            if visited1[e]: continue
            visited1[e] = True
            q.append((e, cd + 1))

    q = deque([(cn, 1)])
    visited2[cn] = True
    while q:
        cn, cd = q.popleft()
        # print(f"{cd = } {cn = }")
        for e in graph[cn]:
            if visited2[e]: continue
            visited2[e] = True
            q.append((e, cd + 1))
    
    if (cd >= maxDist):
        maxNode = cn
        maxDist = cd


print(f"{maxDist}")