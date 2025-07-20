import math
r = int(input())

ans = 0
for i in range(1, r + 1):
    x = i - 0.5
    ans += int(math.sqrt(r * r - x * x) - 0.5)
    # print(f"at x = {x} coords = {int(math.sqrt((r - 0.5) *(r - 0.5) - x * x) - 0.5)}")
print(ans * 4 + 1)
