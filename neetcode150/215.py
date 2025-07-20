import random

class Solution:
    def findKthLargest(self, nums, k: int) -> int:
        random.randint(0, len(nums))
        # print(nums)
        return self.partition(nums, k)

    def partition(self, nums, k):
        div = random.choice(nums)  # select a partition

        # create list based on value relative to partition
        left = [x for x in nums if x < div]
        mid = [x for x in nums if x == div]
        right = [x for x in nums if x > div]

        # check list within k range, do not waste time sorting list not in range of k
        if k <= len(right):
            return self.partition(right, k)

        elif k > len(right) + len(mid):
            return self.partition(left, k - len(right) - len(mid))

        else:
            return mid[0]
