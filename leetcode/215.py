import random


class Solution:
    def findKthLargest(self, nums, k: int) -> int:
        random.randint(0, len(nums))
        # print(nums)
        return self.partition(nums, k)

    def partition(self, nums, k):
        div = random.choice(nums)
        left = [x for x in nums if x < div]
        mid = [x for x in nums if x == div]
        right = [x for x in nums if x > div]

        if k <= len(right):
            return self.partition(right, k)

        elif k > len(right) + len(mid):
            return self.partition(left, k - len(right) - len(mid))

        else:
            return mid[0]


s = Solution()
print(s.findKthLargest([3, 2, 1, 5, 6, 4], k=2))
