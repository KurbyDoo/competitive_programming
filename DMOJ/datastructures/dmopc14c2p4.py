# Author: KurbyDoo
# Creation Date: Jul 19, 2025
# Problem Link: https://dmoj.ca/problem/dmopc14c2p4
# Problem Name: DMOPC '14 Contest 2 P4 - Deforestation
# Status: Solved
# Notes:
#     Original creation date unknown
#     
#     
#     
import sys

n = int(sys.stdin.readline())

array = [0]
sum = 0
for _ in range(n):
    sum += int(sys.stdin.readline())
    array.append(sum)

n = int(sys.stdin.readline())
for _ in range(n):
    start, end = list(map(int, sys.stdin.readline().split()))
    print(array[end + 1] - array[start])