n = int(input())
times = [[0 for _ in range(n)] for _ in range(24)]
for i in range(n):
    a, b = map(int, input().split())
    for j in range(9, 18):
        times[(j + b) % 24][i] = a

best = 0
for i in range(24):
    cur = 0
    for j in range(n):
        cur += times[i][j]

    best = max(cur, best)
print(best)
