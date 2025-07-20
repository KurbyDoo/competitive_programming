# Author: KurbyDoo
# Creation Date: Jul 19, 2025
# Problem Link: https://dmoj.ca/problem/hkccc15s1
# Problem Name: CCCHK '15 S1 - Finding number of pairs
# Status: Solved
# Notes:
#     Original creation date unknown
#     
#     
#     
import sys
import timeit

i = sys.stdin.read().split('\n')
# with open('test.txt') as f:
    # i = f.readlines()

# print(i)
# start = timeit.default_timer()

total = 0
n, m = list(map(int, i.pop(0).split()))
nums = list(map(int, i.pop(0).split()))
nums.sort()

left, right = 0, len(nums) - 1

while left < right:
    if nums[left] + nums[right] <= m:
        total += right - left
        left += 1

    else:
        right -= 1


if total <= 1000000007:
    print(total)

else:
    print(total%1000000007)



# print(timeit.default_timer() - start)

