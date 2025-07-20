n, m = map(int, input().split())
nums = sorted(list(map(int, input().split())))
lft = 0
rht = 0
max_size = 0
# print(*nums)
while rht < n:
    if nums[rht] - nums[lft] < m:
        # print(f"at {lft} - {rht} {nums[rht] - nums[lft]}")
        max_size = max(max_size, rht - lft + 1)
        rht += 1

    else:
        lft += 1
print(max_size)