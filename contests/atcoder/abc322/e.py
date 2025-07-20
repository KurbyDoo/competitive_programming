n, k, p = map(int, input().split())
items = []
dp = [[[float('inf') if k == 0 else 0 for _ in range(k + 1)] for _ in range(110)] for _ in range(110)]
for i in range(1, k + 1):
    dp[0][i] = 0

for i in range(n):
    items.append(list(map(int, input().split())))

for processed in range(n + 1):
    cur_item = items[processed]
    for used in range(n, 0, -1):
        for i in range(n + 1)
        dp[processed][used]

for cur_item in items:
    print(f"{cur_item = }")
    for i in range(n, 0, -1):
        use = False
        if dp[i][0] > dp[i - 1][0] + cur_item[0]:
            use = True

        for j in range(1, k + 1):
            if dp[i][j] < p:
                use = True
        
        print(f"using at {use} {i}")
        if use:
            for j in range(0, k + 1):
                dp[i][j] = dp[i - 1][j] + cur_item[j]

min_cost = float("inf")
for i in range(n + 1):
    valid = True
    for j in range(1, k + 1):
        if dp[i][j] < p:
            valid = False
            break

    if valid and dp[i][0] < min_cost:
        min_cost = dp[i][0]

if min_cost == float('inf'):
    print(-1)

else:
    print(min_cost)

for i in range(n + 1):
    for j in range(k + 1):
        print(f"{dp[i][j]}", end=" ")
    print()