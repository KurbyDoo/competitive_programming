n, k = map(int, input().split())
mod = 998244353
dp = [[0, 0] for i in range(k+1)]
dp[0][0] = 1
# print(dp)
def mm(*args):
    out = 1
    for a in args:
        out = (out * (a % mod)) % mod
    return out
for i in range(k):
    # print(k + 1)
    dp[i + 1][0] = mm(mm(dp[i][0], 1) + mm(dp[i][1], (n - 1)) + mm(dp[i][0], n - 1) + mm(dp[i][0], n - 1, n - 1), pow(n, -2, mod))
    dp[i + 1][1] = mm(mm(dp[i][1], 1) + mm(dp[i][0], (n - 1)) + mm(dp[i][1], n - 1) + mm(dp[i][1], n - 1, n - 1), pow(n, -2, mod))

c1 = dp[k][0]
c2 = mm(dp[k][1], mm(n, n + 1, pow(2, -1, mod)) + mod - 1)
# print(c1, c2, mm(n, n + 1, pow(2, -1, mod)))
# print(dp)
print((c1 + c2) % mod)
# print(mm(3, pow(n, -1, mod)))
# print((499122177 + 1) % mod)
# print((5 * pow(n, -2, mod)) % mod)
# print((4 * pow(n, -2, mod)) % mod)
# print((41 * pow(n, -4, mod)) % mod)
# print((40 * pow(n, -4, mod)) % mod)
# print((40 * pow(n, -4, mod) * 5 + 41 * pow(n, -4, mod)) % mod)
# 1 0
# 5/9 4/9
# 25/81 20/81
# count = [[0 for i in range(n)] for j in range(k + 1)]
# count[0][0] = 1
# for _ in range(k):
#     for a in range(n):
#         for b in range(n):
#             for i in range(n):
#                 if i == a: count[_ + 1][a] += count[_][b]
#                 elif i == b: count[_ + 1][b] += count[_][a]
#                 else: count[_ + 1][i] += count[_][i]
# print(count)
# print((40 * pow(n, -4, mod)) % mod)
# 63/81 18/81
# print((48 * pow(n, -4, mod) * 5 + 33 * pow(n, -4, mod)) % mod)
# for i in range(82):
#     if (i * pow(n, -4, mod) * 5 + (81 - i) * pow(n, -4, mod)) % mod == 554580198:
#         print(i)