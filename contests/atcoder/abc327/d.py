from collections import defaultdict
from collections import deque
n, m = map(int, input().split())
arr = [-1 for _ in range(n + 1)]
r1 = list(map(int, input().split()))
r2 = list(map(int, input().split()))
graph = defaultdict(list)
for i in range(m):
    graph[r1[i]].append(r2[i])
    graph[r2[i]].append(r1[i])

w = "Yes"

arr[0] = 0
for i in range(1, n + 1):
    if w == "No": break
    if arr[i] != -1: continue
    arr[i] = 0
    q = deque([i])
    while q:
        cur = q.popleft()
        for e in graph[cur]:
            if arr[e] == -1:
                arr[e] = 0 if arr[cur] == 1 else 1
                q.append(e)
            else:
                if arr[e] == arr[cur]:
                    w = "No"
                    q = []
                    break

print(w)
