# Author: KurbyDoo
# Creation Date: Jul 19, 2025
# Problem Link: https://codeforces.com/gym/302977/problem/C
# Status: Solved
# Notes:
#     Original creation date unknown
#     
#     
#     
n = int(input())
dp = [float("inf") for _ in range(1 << 3)]
dp[0] = 0
for _ in range(n):
    c, s = input().split()
    c = int(c)
    mask = 0
    if "A" in s:
        mask |= 1
    if "B" in s:
        mask |= 1 << 1
    if "C" in s:
        mask |= 1 << 2
    # print(f"{mask = }")
    for i in range(1 << 3):
        dp[i | mask] = min(dp[i | mask], dp[i] + c)

print(-1 if dp[(1 << 3) - 1] == float("inf") else dp[(1 << 3) - 1])