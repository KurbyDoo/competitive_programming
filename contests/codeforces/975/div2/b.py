from collections import defaultdict
t = int(input())
for _ in range(t):
    count = defaultdict(int)
    n, q = map(int, input().split())
    points = list(map(int, input().split()))
    queries = list(map(int, input().split()))
    ranges = []
    for i in range(1, n):
        ranges.append((points[i - 1] + 1, points[i] - 1, i, n - i))

    for i in range(1, n + 1):
        count[(i - 1) * (n - i + 1) + (n - i)] += 1

    for a, b, c, d in ranges:
        sz =  b - a + 1
        if sz <= 0: continue
        count[c * d] += sz

    for i in queries:
        print(count[i])