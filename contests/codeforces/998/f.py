# t = int(input())
# fact = [1, 1]
# primes = []
MOD = 998244353
# for i in range(2, 100000):
#     fact.append((fact[-1] * i) % MOD)

# for _ in range(t):
#     k, n = map(int, input().split())
#     ans = []
#     for i in range(1, k + 1):
#         if i == 1: ans = n
n = 6969420
choices = ((6969420 * (6969420 + 1)) // 2) % MOD
a = 1 * choices
b = n
print(a)
# print((a * ) % MOD)
b = 124188773

print(((((n * (n + 1) % MOD) * (n + 2)) % MOD) * pow(6, -1, MOD)) % MOD)
print(((((((n * (n + 1) % MOD) * (n + 2)) % MOD) * (n + 3)) % MOD) * pow(12, -1, MOD)) % MOD)
# print((c * pow(b - 1, -1, MOD)) % MOD)
# print((d * pow(c - 1, -1, MOD)) % MOD)
# x = 1 
# ans = n
# [1] [1, 1] [1, 1, 1] ... [1, 1, 1, ..., 1]


# [4] [4 1] [2 2] [1 4]


# 4 3
# [1] [1 1] [1 1 1]
# [2] [2 1] [1 2] [2 1 1] [1 2 1] [1 1 2]
# [3] [3 1] [1 3] [3 1 1] [1 3 1] [1 1 3]
# [4] [4 1] [2 2] [1 4]

# 1C1 + 1C2 + 1C3