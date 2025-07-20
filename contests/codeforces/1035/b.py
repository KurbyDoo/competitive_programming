import math
t = int(input())


def solve():
    n = int(input())
    l, r = 0, 0
    px, py, qx, qy = map(int, input().split())
    dist = math.sqrt((px - qx) * (px - qx) + (py - qy) * (py - qy))
    ai = list(map(int, input().split()))
    for i in range(n):
        if i == 0:
            l, r = ai[i], ai[i]
        else:
            if r - ai[i] <= 0:
                l = abs(r - ai[i])
            else:
                l = max(0, l - ai[i])
            r += ai[i]
    return "Yes" if l <= dist <= r else "No"


while t:
    t -= 1
    print(solve())
