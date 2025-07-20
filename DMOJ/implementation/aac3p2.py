# Author: KurbyDoo
# Creation Date: Jul 19, 2025
# Problem Link: https://dmoj.ca/problem/aac3p2a
# Problem Name: An Animal Contest 3 P2 - Monkey Potato
# Status: Solved
# Notes:
#     Original creation date unknown
#     
#     
#     
k, d = map(int, input().split())
n = list(map(int, input().split()))
n.sort()

if sum(n) == 0:
    print(-1)

elif n[0] == 0:
    if k > 2:
        print(f"{n[1]}{str(n[0])*(k - 2)}{n[1]}")

    else:
        print(f"{str(n[1])*k}")


else:
    print(f"{str(n[0])*k}")
