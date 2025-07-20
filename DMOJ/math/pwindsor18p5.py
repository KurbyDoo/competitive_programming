n = int(input())
ans = n
for i in range(1, n + 1):
    temp = 1
    rem = n % i
    # nums = []
    for j in range(i):
        if (j >= rem): 
            temp *= n // i
            # nums.append(n // i)
        else: 
            temp *= (n // i + 1)
            # nums.append(n // i + 1)
    ans = max(temp, ans)
    # print(temp, ans, i)
    # print(*nums)
print(ans % int(1e9 + 7))