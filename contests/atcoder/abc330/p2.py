n, l, r = map(int, input().split())
nums = list(map(int, input().split()))
ans = []
for i in nums:
    if l <= i <= r:
        ans.append(i)

    elif i < l:
        ans.append(l)

    elif i > r:
        ans.append(r)
print(*ans)