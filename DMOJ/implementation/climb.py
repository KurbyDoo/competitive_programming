# Author: KurbyDoo
# Creation Date: Jul 19, 2025
# Problem Link: https://dmoj.ca/problem/climb
# Problem Name: Rock Climbing
# Status: Solved
# Notes:
#     Original creation date unknown
#     
#     
#     
n, m, e = map(int, input().split())

output = "Too easy!"
a = int(input())
for _ in range(n - 1):
    b = int(input())

    if b - a > m:
        if b - a > 2 * m or e == 0:
            output = "Unfair!"
            break

        e -= 1

    a = b

print(output)
