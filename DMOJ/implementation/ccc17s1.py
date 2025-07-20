# Author: KurbyDoo
# Creation Date: Jul 19, 2025
# Problem Link: https://dmoj.ca/problem/ccc17s1
# Problem Name: CCC '17 S1 - Sum Game
# Status: Solved
# Notes:
#     Original creation date unknown
#     
#     
#     
n = int(input())
t1 = list(map(int, input().split()))
t2 = list(map(int, input().split()))
sum1 = 0
sum2 = 0
max_day = 0
for i in range(n):
    sum1 += t1[i]
    sum2 += t2[i]

    if sum1 == sum2:
        max_day = i + 1

print(max_day)