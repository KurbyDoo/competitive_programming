n, s, k = map(int, input().split())
cost = 0
for i in range(n):
    a, b = map(int, input().split())
    cost += a * b

if cost < s:
    cost += k
print(cost)