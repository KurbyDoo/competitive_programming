ax, ay = map(int, input().split())
bx, by = map(int, input().split())
cx, cy = map(int, input().split())

ans = "No"

if (cy - ay) * (by - ay) == -(cx - ax) * (bx - ax): ans = "Yes"
if (ay - by) * (cy - by) == -(ax - bx) * (cx - bx): ans = "Yes"
if (by - cy) * (ay - cy) == -(bx - cx) * (ax - cx): ans = "Yes"

print(ans)