class Solution:
    def search(self, nums: list[int], target: int) -> int:
        low, hi = 0, len(nums) - 1

        index = -1
        while low <= hi:
            mid = (low + hi) // 2

            if nums[mid] == target:
                return mid

            elif nums[mid] > target:
                hi = mid - 1

            elif nums[mid] < target:
                low = mid + 1

        return index
