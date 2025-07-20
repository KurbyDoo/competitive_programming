from collections import defaultdict
import sys
input = sys.stdin.readline
MOD = 998244353
divisors = [[] for _ in range(100010)]
for i in range(2, 100010):
    for num in range(i * 2, 100010, i):
        divisors[num].append(i)

cache = defaultdict(lambda: defaultdict(int))
def choose(n, k, mod):
    if k == 0: return 1
    if n < k: return 0
    if cache[n][k]: return cache[n][k]
    cache[n][k] = n * choose(n - 1, k - 1, mod) % mod * pow(k, -1, mod) % mod
    return cache[n][k]

dp = [[0] * 100010 for j in range(17)]
for j in range(1, 17):
    for i in range(1, 100000 + 1):
        if j == 1 and i > 1:
            dp[1][i] = 1
        for d in divisors[i]:
            dp[j][i] = (dp[j][i] + dp[j - 1][d]) % MOD

t = int(input())
for _ in range(t):
    k, n = map(int, input().split())

    print(n,end=" ")
    for x in range(2, k):
        ans = 0
        for i in range(1, 17):
            ans = (ans + dp[i][x] * choose(n + 1, i + 1, MOD) % MOD) % MOD
            # print(ans, x, i)
            # print(f"{x = } {i = } {dp[x][i] = }")
            # if (x = 4 and i = 2):
            #     print(f"{dp[2][1] = } ")
        print(ans, end=" ")
    
    if k == 1: continue
    last = 0
    for i in range(1, 17):
        last = (last + dp[i][k] * choose(n + 1, i + 1, MOD) % MOD) % MOD
        # print(ans, x, i)
        # print(f"{x = } {i = } {dp[x][i] = }")
        # if (x = 4 and i = 2):
        #     print(f"{dp[2][1] = } ")
    print(last)
