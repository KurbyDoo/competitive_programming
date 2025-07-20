class Solution(object):
    def twoSum(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        bottom, top = 0, len(numbers) - 1
        while numbers[bottom] + numbers[top] != target:
            if numbers[bottom] + numbers[top] > target:
                top -= 1

            elif numbers[bottom] + numbers[top] < target:
                bottom += 1

        return [bottom + 1, top + 1]
