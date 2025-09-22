import math
A, B = map(int, input().split())
# t(x) = A(g + x)^{-1/2} + Bx
# t'(x) = A(-1/2)(g + x)^{-3/2} + B = 0
# -B = A(-1/2)(g + x)^{-3/2}
# (g + x)^{3/2} = A/(2B)
# (g + x)^3 = (A/(2B))^2
# x = (A/(2B))^{2/3} - g
x = math.pow(A / (2 * B), 2/3) - 1
ans = float('inf')
low = max(0, int(x) - 1)

for i in range(low, low + 4):
    total = A / math.sqrt(1 + i) + B * i
    # print(i, total)
    ans = min(total, ans)
print('{0:.16f}'.format(ans))
