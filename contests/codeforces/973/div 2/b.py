t = int(input())
for _ in range(t):
    n = int(input())
    nums = list(map(int, input().split()))

    s = 0
    for i in range(n - 2):
        s += nums[i]

    print(nums[-1] - nums[-2] + s)