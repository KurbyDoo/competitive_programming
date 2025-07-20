import sys
v1, v2, v3 = map(int, input().split())
a1, b1, c1 = (0, 0, 0)

def get_intersection2(x1, y1, z1, x2, y2, z2):
  h, l, w = 0, 0, 0
  w = max(min(x1, x2) + 7 - max(x1, x2), 0)
  h = max(min(y1, y2) + 7 - max(y1, y2), 0)
  l = max(min(z1, z2) + 7 - max(z1, z2), 0)
  return w * h * l

if 1029 - v2 * 2 - v3 * 3 != v1:
  print("No")
  sys.exit()

for a2 in range(8):
  for b2 in range(8):
    for c2 in range(8):
      for a3 in range(-7, 8):
        for b3 in range(-7, 8):
          for c3 in range(-7, 8):
            l, w, h = 0, 0, 0
            l = max(min([a1, a2, a3]) + 7 - max([a1, a2, a3]), 0)
            h = max(min([b1, b2, b3]) + 7 - max([b1, b2, b3]), 0)
            w = max(min([c1, c2, c3]) + 7 - max([c1, c2, c3]), 0)
            abc = l * w * h
            if abc != v3: continue
            ab = get_intersection2(a1, b1, c1, a2, b2, c2)
            ac = get_intersection2(a1, b1, c1, a3, b3, c3)
            bc = get_intersection2(a3, b3, c3, a2, b2, c2)
            if ab + ac + bc - abc * 3 != v2: continue
            if 1029 - v2 * 2 - v3 * 3 != v1: continue
            print("Yes")
            print(a1, b1, c1, a2, b2, c2, a3, b3, c3)
            sys.exit()
print("No")