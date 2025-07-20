import sys
n, k = map(int, input().split())
nums = list(map(int, input().split()))
if len(nums) == 2:
    if nums[0] <= nums[1]:
        print("Yes\n0")
    
    elif nums[0] - nums[1] >= k:
        print("Yes\n1\n1")
    
    else:
        print("No")

    sys.exit()
    
nums = nums[::-1]
ops = []
idx = 1
last = 0
m = 0
while len(nums) > 2 and m <= 500000:
    while nums[-1] < last:
        nums[-1] += k
        nums[-2] += k
        ops.append(idx)
        ops.append(idx)
        m += 2

    last = nums.pop()
    idx += 1
    
nums = nums[::-1]
a, b = nums[0], nums[1]
while a < last or b < last:
    a += k
    b += k
    ops.append(idx)
    ops.append(idx)
    m += 2
    
if b < a:
    if a - b < k:
        ops.append(idx - 1)
        ops.append(idx - 1)
        m += 2
    ops.append(idx)
    m += 1

if m >= 500000:
    print("No")
    sys.exit()
print("Yes")
print(m)
if m: print(*ops)
# print(f"{last = }")
# print(*nums)
