# Author: KurbyDoo
# Creation Date: Jul 19, 2025
# Problem Link: https://dmoj.ca/problem/coci10c7p3
# Problem Name: COCI '10 Contest 7 #3 Gitara
# Status: Solved
# Notes:
#     Original creation date unknown
#     
#     
#     
import sys
from collections import defaultdict, deque

input = sys.stdin.readline
n, p = map(int, input().split())

strings = [deque() for _ in range(6)]

moves = 0
for _ in range(n):
    s, f = map(int, input().split())
    s = strings[s - 1]

    if s:
        while s[-1] > f:
            s.pop()
            moves += 1

            if not s:
                s.append(f)
                moves += 1

        if s[-1] < f:
            s.append(f)
            moves += 1

    else:
        s.append(f)
        moves += 1

    # for i in strings:
        # print(i)

    # print(f"{moves = }")
print(moves)
    
