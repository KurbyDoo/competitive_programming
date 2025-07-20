n = int(input())

ans = n
l = 1
r = n

while l < r:
    mid = (l + r + 1) // 2
    temp = 1
    for i in range(mid - 1):
        temp *= n // mid
    temp *= n - (n // mid) * (mid - 1)
    
    if temp >= ans:
        l = mid
        ans = temp
    
    else:
        r = mid - 1
print(ans)


