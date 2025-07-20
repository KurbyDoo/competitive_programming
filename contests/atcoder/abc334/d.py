n, q = map(int, input().split())
costs = list(map(int, input().split()))
costs.sort()
psa = [0] * (n + 1)
for i in range(n):
    psa[i + 1] = psa[i] + costs[i]

for _ in range(q):
    amount = int(input())
    l = 0
    r = n
    while l < r:
        mid = (l + r + 1) // 2
        if psa[mid] > amount:
            r = mid - 1

        elif psa[mid] <= amount:
            l = mid

    print(l)