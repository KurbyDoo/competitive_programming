n = int(input())
ans = float('inf')
for _ in range(n):
    w, x, y, z = map(int, input().split())
    if (w - y == 0):
        if w == 0:
            ans = min(ans, min(x, z))
        
        continue
    a = (x - z) / (w - y)
    b = x - a * w
    if b < 0 or (w > 0 and y > 0) or (w < 0 and y < 0):
        continue
    ans = min(ans, b)
print(-1.0 if ans == float('inf') else ans)
