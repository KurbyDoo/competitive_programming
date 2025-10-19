n, k = map(int, input().split())
scores = sorted([int(input()) for _ in range(n)])

psa = [0] * (n + 1)
psa2 = [0] * (n + 1)
for i in range(1, n + 1):
    psa[i] = psa[i - 1] + scores[i - 1]
    psa2[i] = psa2[i - 1] + scores[i - 1] * scores[i - 1]

# sum_x (sumx/n - x_i)^2 = sumx (sumx/n^2 - 2 * xi * sumx/n + xi^2) = (sumx)^/n - 
ans = float('inf')

for i in range(k, n + 1):
    t = psa[i] - psa[i - k]
    t2 = psa2[i] - psa2[i - k]
    mew = t / k
    error = k * mew * mew + t2 - 2 * mew * t
    ans = min(error, ans)
    
print(ans)
