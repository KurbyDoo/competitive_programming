# KurbyDoo
# Feb 22th 2023
# WC '99 P1 - The Matrix
# https://dmoj.ca/problem/wc99p1

import sys
input = sys.stdin.readline

while True:
    n = int(input())
    if n == -1:
        break

    operations = []

    line = input()
    while line[0] != "(":
        operations.append(line[line.find("[") + 1:line.find("]")].split())
        line = line[line.find("]") + 1:]

    original = line[1:-2].split()

    # print(operations, original)

    for o in operations[::-1]:
        new = []
        for move in o:
            new.append(original[int(move)-1])


        original = new

    print("(", end="")
    print(*original, end="")
    print(")")
        
            