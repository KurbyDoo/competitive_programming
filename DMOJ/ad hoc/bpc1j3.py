n = int(input())
nums = sorted(list(map(int, input().split())))
ans = 0
for i in range(n):
    ans += nums[i * 2 + 1] - nums[i * 2]
print(ans)