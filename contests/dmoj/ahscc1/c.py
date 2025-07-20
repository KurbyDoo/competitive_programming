n = int(input())
s1 = input()
s2 = input()
dp = [[0] * (n + 1) for i in range(2)]
for i in range(1, n):
    dp[0][i] = dp[0][i - 1] + (1 if s1[i - 1] == s2[i - 1] else 0)
    dp[1][i] = max(dp[1][i - 1], dp[0][i - 1]) + (1 if s1[i] == s2[i - 1] else 0)
print(max(dp[0][n], dp[1][n - 1]))