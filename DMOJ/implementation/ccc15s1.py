# Author: KurbyDoo
# Creation Date: Jul 19, 2025
# Problem Link: https://dmoj.ca/problem/ccc15s1
# Problem Name: CCC '15 S1 - Zero That Out
# Status: Solved
# Notes:
#     Original creation date unknown
#     
#     
#     
n = int(input())

s = []
past = 0
for _ in range(n):
    next = int(input())
    if next != 0:
        s.append(next)

    else:
        s.pop(-1)

if s:
    print(sum(s))

else:
    print(0)

