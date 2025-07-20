from collections import defaultdict
import math
n = int(input())
gears = defaultdict(list)
for _ in range(n):
    s, c = map(int, input().split())
    gears[s].append(c)

ans = 0
for size in gears:
    gears[size].sort()
    if len(gears[size]) > 1:
        for i in range(len(gears[size]) // 2):
            ans += math.log(gears[size][-1 - i] / gears[size][i])
print(ans)