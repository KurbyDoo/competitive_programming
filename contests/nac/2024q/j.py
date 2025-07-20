import sys
l, x1, x2, y1, y2, z1, z2 = map(int, input().split())

for i in range(l):
    x1, y1, z1 = x1 * 3, y1 * 3, z1 * 3
    center = 0
    if (x2 < x1 < 2 * x2): center += 1
    if (y2 < y1 < 2 * y2): center += 1
    if (z2 < z1 < 2 * z2): center += 1
    if center >= 2:
        print(0)
        sys.exit()
    if (x1 > x2): x1 %= x2
    if (y1 > y2): y1 %= y2
    if (z1 > z2): z1 %= z2
print(1)