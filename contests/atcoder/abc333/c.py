n = int(input())
nums = set()
for i in range(1, 15):
    for j in range(1, 15):
        for k in range(1, 15):
            nums.add(int("1" * k) + int("1" * j) + int("1" * i))

nums = list(sorted(nums))
print(nums[n - 1])