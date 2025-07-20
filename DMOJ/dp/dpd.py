import sys
input = sys.stdin.readline

n, maxWeight = map(int, input().split())
items = [list(map(int, input().split())) for _ in range(n)]

# dp = [0 for _ in range(maxWeight + 1)]

# for cost, value in items:
#     for w in range(maxWeight, 0, -1):
#         if (w - cost >= 0 and w > 0):
#             dp[w] = max(dp[w - cost] + value, dp[w - 1])
# # print(*dp)
# print(max(dp))

dp = [[0 for _ in range(maxWeight + 1)] for _ in range(n + 1)]

for i in range(n + 1):
    for w in range(maxWeight + 1):
        if i == 0 or w == 0:
            continue

        elif items[i - 1][0] > w:
            dp[i][w] = dp[i - 1][w]

        elif i > 0 and w >= items[i - 1][0]:
            dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - items[i - 1][0]] + items[i - 1][1])

print(dp[n][maxWeight])