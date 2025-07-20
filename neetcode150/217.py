class Solution(object):
    def containsDuplicate(self, nums):
        cache = {}

        # For every number
        for n in nums:

            # If number has been seen before
            if cache.get(n, False):
                return True

            # Else add it to the cache
            cache[n] = True
