import random

n = int(input())
nums = list(map(int, input().split()))
if n == 1: print("1 1")
elif n == 3: print(f"{nums.index(3) + 1} {nums.index(3) + 1}")
elif (nums[0] == 1): print(f"2 {n}")
elif (nums[-1] == 1): print(f"1 {n - 1}")
else: print(f"1 {n}")


    


nums = [i+1 for i in range(10)]

for _ in range(1000):
    random.shuffle(nums)

    best = 0
    best_index = (0, 0)
    for i in range(10):
        for j in range(i, 10):
            total = 1
            for x in range(i, j + 1):
                total *= nums[x]

            total //= (j - i + 1)

            if (total > best):
                best_index = (i + 1, j + 1)
                best = total

    if (best_index[0] != 1 and best_index[1] != 10):
        print(*nums)