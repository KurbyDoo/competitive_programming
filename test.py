# from random import randint
# N = 20000
# n = [0] + [randint(1, 100) for i in range(3000)]
# prefix_sum = [0] * (len(n))
# for i in range(1, len(n)):
#     prefix_sum[i] += prefix_sum[i - 1] + n[i]
# def increment(r):
#     if randint(1, n[reg + 1]) == 1:
#         return r + 1
#     return r

# def query(r):
#     return prefix_sum[r]

# ans = []
# s1, s2 = 0, 0
# for _ in range(N):
#     reg = 0
#     trials = randint(1, 1000)

#     for i in range(trials):
#         reg = increment(reg)
    
#     s1 += trials
#     s2 += query(reg)

# # print(ans)
# print(s1, s2)
# print(f"error = {(s1 - s2) / s1}")


n = [0] + [i + 1 for i in range(25)]
N = [0] * 30
for i in range(26):
    N[i] = N[i - 1] + n[i]
pr = [[0] * 20 for i in range(20)]

pr[0][0] = 1
for t in range(1, 20):
    for k in range(0, t + 1):
        if k == 0:
            pr[t][k] = pr[t - 1][k] * (1 - 1/n[k + 1])
        else:
            pr[t][k] = (1/n[k]) * pr[t - 1][k - 1] + (1 - 1/n[k + 1]) * pr[t - 1][k]

for t, row in enumerate(pr):
    for a in row:
        print(f"{a:.3f}", end=" ")
    print(f" | {sum(row):.5f} | {sum(N[k] * pr[t][k] for k in range(1, t + 1)):.5f} | {pow(1 - 1/n[1], t - 1) + sum(pr[t-1][k] for k in range(1, t)) + t - 1 if t > 0 else 0} | {pow(1 - 1/n[1], t - 1) + sum(pr[t-1][k] for k in range(1, t)) + t - 1 if t > 0 else 0}")
