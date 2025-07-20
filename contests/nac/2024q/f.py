import math
x1, y1, x2, y2, major = map(int, input().split())
cx, cy = (x1 + x2) / 2, (y1 + y2) / 2
angle = math.atan2((y2 - y1), (x2 - x1))
minor = math.sqrt(major * major / 4 - (x1 - cx) * (x1 - cx) - (y1 - cy) * (y1 - cy))

# print(major, minor, angle, math.degrees(angle))

ux = major / 2 * math.cos(angle)
uy = major / 2 * math.sin(angle)
vx = minor * math.cos(angle - math.pi/2)
vy = minor * math.sin(angle - math.pi/2)

# print(ux, uy, vx, vy)

hw = math.sqrt(ux*ux + vx*vx)
hh = math.sqrt(uy*uy + vy*vy)
# print(hw, hh)
print(cx - hw, cy - hh, cx + hw, cy + hh)
