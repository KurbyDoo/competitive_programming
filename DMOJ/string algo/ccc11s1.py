# Author: KurbyDoo
# Creation Date: Jul 19, 2025
# Problem Link: https://dmoj.ca/problem/ccc11s1
# Problem Name: CCC '11 S1 - English or French?
# Status: Solved
# Notes:
#     Original creation date unknown
#     
#     
#     
from collections import Counter


number = int(input())

s = 0
t = 0

for _ in range(number):
    d = Counter(input())
    s += d["s"]
    s += d["S"]
    t += d["t"]
    t += d["T"]

if s >= t: print("French")
else: print("English")
