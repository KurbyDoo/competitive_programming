# THIS IS COPIED CODE FROM https://leetcode.com/problems/first-missing-positive/discuss/2661122/Easy-to-understand-or-O(1)-Space-O(n)-Time-Python

def firstMissingPositive(nums) -> int:
    def swap(i, j):
        nums[i], nums[j] = nums[j], nums[i]

    n = len(nums)
    for i in range(n):
        while nums[i] != i + 1: # check if new element after swap is in wrong location
            j = nums[i] - 1
            if 0 <= j < n and nums[j] != nums[i]:
                swap(i, j)

            else:
                break
            

    for i in range(n):
        if nums[i] != i + 1:
            return i + 1
    return n + 1


# print(firstMissingPositive([-3, -6, 5, 9, 11, 1, 2, 8, 4, -3, 7, 4, 3]))
# print(firstMissingPositive([1, 2, 0]))
# print(firstMissingPositive([3, 4, -1, 1]))
# print(firstMissingPositive([7, 8, 9, 11, 12]))
