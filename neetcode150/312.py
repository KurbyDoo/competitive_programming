class Solution:
    def maxCoins(self, nums: list[int]) -> int:
        # Add empty balloons to the ends of the array
        nums = [1] + nums + [1]

        # Create an array of arrays to store the max coins
        cache = [[0 for _ in range(len(nums))] for _ in range(len(nums))]

        def calc(left, right):

            # If sub array is empty
            if left > right:
                return 0

            # If value of sub array has already been calculated
            if cache[left][right]:
                return cache[left][right]

            # Calculate the value of this sub array
            for i in range(left, right + 1):

                # Calculate number of coins from balloon i
                coins = nums[left - 1] * nums[i] * nums[right + 1]

                # Calculate number of coins from surrounding sub arrays
                coins += calc(left, i - 1) + calc(i + 1, right)

                # Add value to the cache for future use
                cache[left][right] = max(cache[left][right], coins)

            return cache[left][right]

        # Return value sub array excluding start and end balloons
        return calc(1, len(nums) - 2)
