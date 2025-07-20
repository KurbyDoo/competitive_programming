x1, y1, x2, y2 = map(int, input().split())
# m = (y2 - y1)/(x1 - x2)
# m = (y - y1)/(x - x1) => m(x - x1) + y1 = y
mx = min(x1, x2)
my = min(y1, y2)
Mx = max(x1, x2)
My = max(y1, y2)
n = int(input())
ans = 0
def check(pt1, pt2):
    if x2 - x1 == 0 and pt2[0] - pt1[0] == 0: return False
    if x2 - x1 == 0:
        m2 = (pt2[1] - pt1[1]) / (pt2[0] - pt1[0])
        # m = (y - y1)/(x - x1) => m(x - x1) + y1 = y
        y = m2 * (x1 - pt1[0]) + pt1[1]
        return my <= y <= My and min(pt1[1], pt2[1]) <= y <= max(pt1[1], pt2[1])
    elif pt2[0] - pt1[0] == 0:
        m1 = (y2 - y1) / (x2 - x1)
        y = m1 * (pt1[0] - x1) + y1
        return my <= y <= My and min(pt1[1], pt2[1]) <= y <= max(pt1[1], pt2[1])
    else:
        m1 = (y2 - y1) / (x2 - x1)
        m2 = (pt2[1] - pt1[1]) / (pt2[0] - pt1[0])

        if m1 == m2: return False
        
        # m1 * (x - x1) + y1 = m2 * (x - p1.x) + p1.y
        # m1 * x - m1 * x1 + y1 = m2 * x - m2 * p1.x) + p1.y
        # m1 * x - m2 * x = x1 * m1 - m2 * p1.x + p1.y - y1
        # x = (x1 * m1 - p1x * m2 + p1y - y1)/(m1 - m2)
        x = (x1 * m1 - pt1[0] * m2 + pt1[1] - y1) / (m1 - m2)
        return mx <= x <= Mx and min(pt1[0], pt2[0]) <= x <= max(pt1[0], pt2[0])

for _ in range(n):
    num, *points = list(map(int, input().split()))
    pts = []
    for i in range(0, num * 2, 2):
        pts.append((points[i], points[i + 1]))

    pts.append(pts[0])
    for i in range(num):
        if check(pts[i], pts[i + 1]):
            ans += 1
            break

print(ans)
# 0 0 3 3
# 3
# 4 1 2 2 2 2 1 1 1
# 4 3 2 4 2 4 1 3 1
# 4 2 2 3 2 3 1 2 1