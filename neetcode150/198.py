class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 1:
            return nums[-1]

        elif len(nums) == 2:
            return max(nums[-1], nums[-2])

        n1, n2 = nums[0], nums[1]

        for i in range(2, len(nums)):
            new = nums[i] + n1
            n1 = max(n2, n1)
            n2 = new

        return max(n1, n2)
