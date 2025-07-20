# Author: KurbyDoo
# Creation Date: Jul 19, 2025
# Problem Link: https://leetcode.com/problems/count-of-smaller-numbers-after-self/submissions/1704164081/
# Problem Name: 315. Count of Smaller Numbers After Self
# Status: Solved
# Notes:
#     Original creation date unknown
#     
#     
#     
import cProfile

class Solution:
    def countSmaller(self, nums):
        sorted_nums, answer = sorted(nums), []

        for n in nums:
            i = self.search(sorted_nums, n)
            answer.append(i)
            del sorted_nums[i]

        return answer

    def search(self, sorted_nums, n):
        low, hi = 0, len(sorted_nums) - 1
        i = -1

        while (low <= hi):
            mid = (low + hi)//2

            if sorted_nums[mid] == n:
                i = mid
                hi = mid - 1

            elif sorted_nums[mid] > n:
                hi = mid - 1

            elif sorted_nums[mid] < n:
                low = mid + 1

        return i

s = Solution()
with open("test.txt") as f:
    sc = f.read()
    array = sc.pop(0)
cProfile.run(s.countSmaller(array))

