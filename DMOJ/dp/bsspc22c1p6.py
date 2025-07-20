n, m = map(int, input().split())

players = [list(map( int, input().split())) for _ in range(n)]
players.sort(reverse=True)
# print(players)

dp = [[10000000000000 for _ in range(n + 1)] for _ in range(m + 1)]
dp[0][0] = 0
for i in range(n + 1):
    for w in range(m + 1):
        if (i == 0 or w == 0):
            if (i > 0):
                dp[w][i] = dp[w][i - 1]
                
            continue
        dp[w][i] = min(dp[w][i - 1], dp[w - 1][i - 1] + players[i - 1][0] * (w - 1) + players[i - 1][1])

# for r in dp:
#     print(*r)
print(min(dp[m]))