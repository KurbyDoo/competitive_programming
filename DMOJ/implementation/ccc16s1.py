# Author: KurbyDoo
# Creation Date: Jul 19, 2025
# Problem Link: https://dmoj.ca/problem/ccc16s1
# Problem Name: CCC '16 S1 - Ragaman
# Status: Solved
# Notes:
#     Original creation date unknown
#     
#     
#     
import sys

one = list(input())
two = list(input())

alphabet = list('abcdefghijklmnopqrstuvwxyz*')

oneCount = [0 for _ in range(26)]
twoCount = [0 for _ in range(26)]
extra = 0

for c in one:
    oneCount[alphabet.index(c)] += 1

for c in two:
    if c != '*':
        twoCount[alphabet.index(c)] += 1

    else:
        extra += 1

for i in range(26):
    if oneCount[i] < twoCount[i]:
        print('N')
        sys.exit()

    elif oneCount[i] > twoCount[i]:
        extra -= oneCount[i] - twoCount[i]
        if extra < 0:
            print('N')
            sys.exit()


print('A')