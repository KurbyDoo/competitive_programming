n = int(input())
aoki = 0
takahashi = 0
choices = []
for _ in range(n):
    a, b, c = map(int, input().split())
    if a > b: takahashi += c
    else: 
        aoki += c
        choices.append(((b - a + 1) // 2, c))
# print(aoki, takahashi)
target = max(0, (aoki - takahashi + 1) // 2)

dp = [float('inf')] * (100010)
dp[0] = 0
for a, b in choices:
    for i in range(100000, b - 1, -1):
        dp[i] = min(dp[i], dp[i - b] + a)

print(min(dp[target:]))

