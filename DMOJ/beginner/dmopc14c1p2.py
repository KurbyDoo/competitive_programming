import math

n, m = map(int, input().split())
t = int(input())

print(math.floor(n/t) * math.floor(m/t))
