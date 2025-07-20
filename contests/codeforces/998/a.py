t = int(input())
for _ in range(t):
    a, b, c, d = map(int, input().split())
    ans = (0, 0)
    for i in range(-200, 201):
        count = 0
        count += a + b == i
        count += b + i == c
        count += i + c == d
        if ans[0] < count:
            ans = (count, i)

    print(ans[0])