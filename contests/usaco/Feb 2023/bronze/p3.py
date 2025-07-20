n, k = map(int, input().split())
days = list(map(int, input().split()))

cost = k + 1
for i in range(n - 1):
    if days[i + 1] - days[i] > k:
        # print(f"rebuying for {k + 1}")
        cost += k + 1

    else:
        # print(f"continue for {days[i + 1] - days[i]}")
        cost += days[i + 1] - days[i]

print(cost)

# 13 2
# 1 23 24 25 26 27 31 32 34 35 36 37 40
