import sys
input = sys.stdin.readline

n, k = map(int, input().split())
s = list(map(int, input().split()))

mem = [float('inf') for _ in range(n + 1)]
mem[0] = 0

for i in range(n):
    for j in range(1, k + 1):
        if i + j < n:
            mem[i + j] = min(mem[i + j], mem[i] + abs(s[i] - s[i + j]))


print(mem[-2])