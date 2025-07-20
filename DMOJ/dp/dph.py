import sys

input = sys.stdin.readline

h, w = map(int, input().split())
grid = []
dp = [[0 for _ in range(w)] for _ in range(h)]

for i in range(h):
    grid.append(list(input()))

for c in range(w):
    for r in range(h):
        if grid[r][c] == "#": continue
        elif r == c == 0: dp[r][c] = 1
        elif r == 0: dp[r][c] = dp[r][c - 1]
        elif c == 0: dp[r][c] = dp[r - 1][c]
        else: dp[r][c] = int((dp[r - 1][c] + dp[r][c - 1]) % (10e8 + 7))

print(dp[-1][-1])

