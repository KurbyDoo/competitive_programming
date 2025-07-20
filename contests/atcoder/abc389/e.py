import heapq
n, m = map(int, input().split())
prices = list(map(int, input().split()))
used = [0] * (n + 1)
def solve(end):
    cur = 0
    for p in prices:
        x = (end + p) // (2 * p)
        cur += x * x * p

    return cur

l = 0
r = m
while l < r:
    mid = (l + r + 1) // 2
    if solve(mid) > m: r = mid - 1
    else: l = mid 

ans = 0
cur = 0
for i in range(n):
    x = (l + prices[i]) // (2 * prices[i])
    used[i] = x
    ans += x
    cur += x * x * prices[i]

pq = [((2 * used[i] + 1) * prices[i], i) for i in range(n)]
heapq.heapify(pq)

while True:
    (np, ni) = heapq.heappop(pq)
    if np + cur > m: break
    ans += 1
    used[ni] += 1
    cur += np
    heapq.heappush(pq, ((2 * used[ni] + 1) * prices[ni], ni))

print(ans)
        
