# Author: KurbyDoo
# Creation Date: Jul 19, 2025
# Problem Link: https://dmoj.ca/problem/aac2p1
# Problem Name: An Animal Contest 2 P1 - Koala Konundrum
# Status: Unsolved
# Notes:
#     Original creation date unknown
#     
#     
#     
from collections import defaultdict

###UNFINISHED

n = int(input())
s = input()
count = defaultdict(int)

for c in s:
    count[c] += 1

for a in count.keys():
    print(f"{a}", end=": ")
    print(f"{count[a] = }")

    # htisseeessith, w, n, m, p, o, r, u,

