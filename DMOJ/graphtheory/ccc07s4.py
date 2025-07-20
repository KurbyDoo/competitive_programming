# Author: KurbyDoo
# Creation Date: Jul 19, 2025
# Problem Link: https://dmoj.ca/problem/ccc07s4
# Problem Name: CCC '07 S4 - Waterpark
# Status: Solved
# Notes:
#     Original creation date unknown
#     
#     
#     
import sys
from collections import defaultdict, deque
input = sys.stdin.readline

n = int(input())

m = [0 for _ in range(n + 1)]
m[1] = 1
g = defaultdict(list)

while True:
    a, b = map(int, input().split())

    if not (a and b):
        break

    g[b].append(a)

for i in range(2, n + 1):
    sum = 0
    for c in g.get(i, []):
        sum += m[c]
    m[i] = sum


print(m[-1])