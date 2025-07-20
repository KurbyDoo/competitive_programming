n = int(input())
nums = []
for last in range(10):
    for a in range(10):
        for b in range(10):
            if a * b == last:
                nums.append(f"{str(a)}{str(b)}{last}")
nums.sort()
for num in nums:
    if int(num) >= n:
        print(num)
        break