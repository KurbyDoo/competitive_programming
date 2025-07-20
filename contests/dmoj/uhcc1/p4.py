import math
n = int(input())
points = []
x_points = []
y_points = []
for i in range(n):
    a, b = map(int, input().split())
    x_points.append(a)
    y_points.append(b)
    points.append((a, b))
# print(x_avg / n, y_avg / n)
x_points.sort()
y_points.sort()
l = 0
r = n - 1
while l < r:
    l += 1
    r -= 1
if l == r:
    x_coord_l = x_points[l]
    x_coord_r = x_points[l]

else:
    x_coord_l = x_points[r]
    x_coord_r = x_points[l]

l = 0
r = n - 1
while l < r:
    l += 1
    r -= 1

if l == r:
    y_coord_l = y_points[l]
    y_coord_r = y_points[l]

else:
    y_coord_l = y_points[r]
    y_coord_r = y_points[l]

x_avg = (x_coord_l + x_coord_r) // 2
y_avg = (y_coord_l + y_coord_r) // 2
# print(x_avg, y_avg)

def test_point(sx, sy):
    dist = 0
    for a, b in points:
        dist += abs(a - sx) + abs(b - sy)

    return dist


best = float('inf')
best_point = ()
second = best
second_point = ()
for i in [-1, 0, 1]:
    for j in [-1, 0, 1]:
        res = test_point(x_avg + i, y_avg + j)
        if res <= best:
            second = best
            second_point = best_point
            best = res
            best_point = (x_avg + i, y_avg + j)

        elif res < second:
            second = res
            second_point = (x_avg + i, y_avg + j)

print(best + second)
# print(best_point, second_point)
# 4
# 6 2
# 10 2
# 2 6
# 10 8

# 4
# 0 1
# 100 3
# 0 2
# 0 3