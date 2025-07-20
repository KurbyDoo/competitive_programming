# Author: KurbyDoo
# Creation Date: Jul 19, 2025
# Problem Link: https://dmoj.ca/problem/bfs19p1
# Problem Name: Back From Summer '19 P1: Winnie's Orphans
# Status: Solved
# Notes:
#     Original creation date unknown
#     
#     
#     
import sys
inputs = sys.stdin.read().split('\n')
# with open('test.txt') as f:
#     inputs = f.readlines()

n, m = list(map(int, inputs.pop(0).split()))

nums = []
for i in range(n):
    children = list(map(int, inputs.pop(0).split()))
    total = 0
    for child in children:
        if child not in [1, 10]:
            total += 1


    nums.append(total)

print(nums.index(max(nums)) + 1)
