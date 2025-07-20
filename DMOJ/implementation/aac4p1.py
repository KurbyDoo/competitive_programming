# Author: KurbyDoo
# Creation Date: Jul 19, 2025
# Problem Link: https://dmoj.ca/problem/aac4p1
# Problem Name: An Animal Contest 4 P1 - Dasher's Digits
# Status: Solved
# Notes:
#     Original creation date unknown
#     
#     
#     
n, m = map(int, input().split())

s = input()
nums = list(map(int, input().split()))
i = m - nums[::-1].index(max(nums)) - 1

s = s.replace('0', '', i)
i = s.index('0')
s = s[i:] + s[:i]
print(s.replace('0', ''))
