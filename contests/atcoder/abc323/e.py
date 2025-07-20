n, x = map(int, input().split())
songs = list(map(int, input().split()))
dp = [0] * (x + 1)
dp[0] = 1
mod = 998244353
# print((7/27) % 998244353)
# print((7 * pow(27, -1, 998244353)) % 998244353)
# print((1 * pow(3, -1, 998244353)) % 998244353)
count = 0
for i in range(0, x + 1):
    if i != 0: dp[i] = (dp[i] * pow(n, -1, mod)) % mod
    if (i + songs[0] > x): count = (count + (dp[i] * pow(n, -1, mod))) % mod
    for song in songs:
        if song + i <= x:
            dp[i + song] += dp[i]


# print(*dp)
print(count)
