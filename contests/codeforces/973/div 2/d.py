t = int(input())
for _ in range(t):
    n = int(input())
    psa = [0] * (n + 1)
    nums = list(map(int, input().split()))
    for i in range(n, 0, -1):
        psa[i] += nums[i]
        psa[i - 1] = psa[i]

    print(*psa)
    max_num = max(nums)
    min_num = min(nums)

    for i in range(n, 0, -1):
        if nums[i] > min_num:
            total = psa[i]
            

