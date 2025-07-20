k = int(input())

nums = []

def test(n):
    if (len(n) == 1): return 200
    for i in range(len(n) - 1):
        if int(n[i]) <= int(n[i + 1]):
            return i
    return 200
n = 1
while n < 10000000000:
    result = test(str(n))

    if result == 200:
        nums.append(n)
        n += 1

    else:
        n += 10 ** (len(str(n)) - result - 1)
        n -= n % (10 ** (len(str(n)) - result - 1))

    if len(nums) == k:
        break

# print(nums)
print(nums[k - 1])