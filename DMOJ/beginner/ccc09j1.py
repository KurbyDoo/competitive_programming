nums = list(map(int, list("9780921418"))) + [int(input()), int(input()), int(input())]
sum = 0
for i in range(13):
    if i%2 == 0:
        sum += nums[i]

    else:
        sum += nums[i] * 3
print(f"The 1-3-sum is {sum}")
