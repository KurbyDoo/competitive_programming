n = int(input())

nums = list(map(int, input().split()))

l = 0
r = 1

biggest = 0
while l < n and r < n:
    if nums[r] > nums[l] and nums[r] > nums[r - 1]:
        # print(f"between {l, r} = {nums[r] - nums[l]}")
        biggest = max(biggest, nums[r] - nums[l])
        r += 1

    else:
        l = r
        r = l + 1

print(biggest)
