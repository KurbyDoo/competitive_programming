import math

def solve():
    a, b, x, y = map(int, input().split())
    cost = [math.inf] * 101
    cost[a] = 0
    if a == b:
        return 0
    if b < a:
        if a ^ 1 == b:
            return y

        return -1

    while a < b:
        cost[a + 1] = min(cost[a + 1], cost[a] + x)
        cost[a ^ 1] = min(cost[a ^ 1], cost[a] + y)
        a += 1
    return cost[b]


t = int(input())

while t:
    t -= 1
    print(solve())
