### LEETCODE 01

def twoSum(nums, target):
    one = 0
    two = len(nums) - 1
    while True:
        print(one, two)
        s = nums[one] + nums[two]
        if s == target:
            print([one, two])
            break

        elif s > target:
            two -= 1

        elif s < target:
            one += 1


twoSum([-1, -2, -3, -4, -5], -8)
