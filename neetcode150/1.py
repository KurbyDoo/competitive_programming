class Solution(object):
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        checked = {}
        for i, n in enumerate(nums):
            if n in checked:
                return [checked[n], i]

            checked[target - n] = i
