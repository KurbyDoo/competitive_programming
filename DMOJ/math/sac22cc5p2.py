# Author: KurbyDoo
# Creation Date: Jul 19, 2025
# Problem Link: https://dmoj.ca/problem/sac22cc5p2
# Problem Name: SAC '22 Code Challenge 5 P2 - Querying Extensions
# Status: Solved
# Notes:
#     Original creation date unknown
#     
#     
#     
num = int(input())

direction = input()

if direction == "right":
    if num%2 == 0:
        print('left')

    else:
        print('right')

else:
    if num%2 == 0:
        print('right')

    else:
        print('left')