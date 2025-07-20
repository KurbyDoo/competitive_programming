t = int(input())
for _ in range(t):
    n = int(input())
    nums = list(map(int,input().split()))
    for i in range(n - 1):
        if nums[i] > nums[i + 1] and abs(nums[i + 1] - nums[i]) == 1:
            nums[i], nums[i + 1] = nums[i + 1], nums[i]
    for i in range(n - 1):
        if nums[i] > nums[i + 1] and abs(nums[i + 1] - nums[i]) == 1:
            nums[i], nums[i + 1] = nums[i + 1], nums[i]
    for i in range(n - 1):
        if nums[i] > nums[i + 1] and abs(nums[i + 1] - nums[i]) == 1:
            nums[i], nums[i + 1] = nums[i + 1], nums[i]
    
    print("YES" if nums == sorted(nums) else "NO")
