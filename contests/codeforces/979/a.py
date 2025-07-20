t = int(input())
for _ in range(t):
    n = int(input())
    nums = list(map(int, input().split()))
    big = max(nums)
    small = min(nums)
    print((big - small) * (n - 1))