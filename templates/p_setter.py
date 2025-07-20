import random, sys
nums = set()
while len(nums) < 1e5:
    nums.add(random.randint(1, 1e9))
nums = list(nums)
random.shuffle(nums)
print(*nums, file=sys.stderr)
