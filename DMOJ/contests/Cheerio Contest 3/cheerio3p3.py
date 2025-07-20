import math
n, m = map(int, input().split())

number = round(math.sqrt(n * 2)) // 2

nums = list(range(1, number + 1)) + list(range(number * 2 + 1, n + 1, number * 2 + 1))

if nums[-1] + number < n and len(nums) < m:
    nums.append(n - number)

print(len(nums))
print(*nums)

# 18 6

# 100 14

# 24 6

# 40 8

# 21 6
