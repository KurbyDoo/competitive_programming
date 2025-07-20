import math
t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    ans = 0
    while n > 0:
        x = int(math.log(n, k)) if k != 1 else 0
        times = n // (k ** x)
        ans += times
        n -= times * (k ** x)
    print(ans)