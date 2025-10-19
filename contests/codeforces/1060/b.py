t = int(input())
for _ in range(t):
    n = int(input())
    nums = [float('inf')] + list(map(int, input().split())) + [float('inf')]
    premax = [0] * (n + 1)
    ans = 0
    for i in range(1, n + 1):
        premax[i] = max(premax[i - 1], nums[i])
        if i % 2 == 0:
            nums[i] = premax[i]
    # print(nums)
    for i in range(1, n + 1):
        if i % 2 == 0: continue
        ans += max([nums[i] - nums[i - 1] + 1, nums[i] - nums[i + 1] + 1, 0])
    print(ans)