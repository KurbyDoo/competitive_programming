n, k, c = map(int, input().split())
dp = [1] * (n + 1)
MOD = 998244353
for i in range(1, n + 1):
    if (i < k):
        if c == 2:
            dp[i] = dp[i - k] * pow(2, k, MOD) % MOD
        else:
            dp[i] = (((c * (c - 1) // 2) % MOD) % MOD * pow(2, i, MOD) % MOD + (MOD - (c * (c - 1) // 2) % MOD)) % MOD
        
    else:
        if c == 2:
            dp[i] = dp[i - k] * pow(2, k, MOD) % MOD
        else:
            dp[i] = (dp[i - k] * ((c * (c - 1) // 2) % MOD) % MOD * pow(2, k, MOD) % MOD + (MOD - (c * (c - 1) // 2) % MOD)) % MOD

print(*dp)
print(dp[n])