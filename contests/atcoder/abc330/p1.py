n, l = map(int, input().split())
ans = 0
nums = list(map(int, input().split()))
for i in nums:
    if i >= l:
        ans += 1
print(ans)