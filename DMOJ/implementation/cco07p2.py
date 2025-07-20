import sys
from collections import defaultdict
input = sys.stdin.readline
n = int(input())
found = set()
ans = "No two snowflakes are alike."
for i in range(n):
    s = input().split()
    rev = s[::-1]
    min_s = "-".join(s)
    min_r = "-".join(rev)
    for i in range(6):
        s = s[1:] + [s[0]]
        rev = rev[1:] + [rev[0]] 
        min_s = min(min_s, "-".join(s))
        min_r = min(min_r, "-".join(rev))
    # print(min_s)
    # print(min_r)
    if min_s in found or min_r in found:
        ans = "Twin snowflakes found."
        break
    found.add(min_s)
    found.add(min_r)
print(ans)