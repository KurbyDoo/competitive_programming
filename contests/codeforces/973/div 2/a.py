t = int(input())
for _ in range(t):
    n = int(input())
    x, y = map(int, input().split())

    small = min(x, y)
    print(((n + small - 1) // small))