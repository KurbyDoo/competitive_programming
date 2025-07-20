dp = [float('inf')] * 130
dp[0] = 0
n, s, m, l = map(int, input().split())
for i in range(n + 12):
    dp[i + 6] = min(dp[i + 6], dp[i] + s)
    dp[i + 8] = min(dp[i + 8], dp[i] + m)
    dp[i + 12] = min(dp[i + 12], dp[i] + l)

print(min(dp[n:]))