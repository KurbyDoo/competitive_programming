# |x2 + y2 - D| = 0
# x2 + y2 = D
import math
D = int(input())
ans = float('inf')
for x in range(2000000):
    if D - x * x < 0: continue
    y2 = int(math.sqrt(D - x * x))
    y1 = y2 - 1
    y3 = y2 + 1
    ans = min(ans, abs(x * x + y1 * y1 - D))
    ans = min(ans, abs(x * x + y2 * y2 - D))
    ans = min(ans, abs(x * x + y3 * y3 - D))

print(int(ans))