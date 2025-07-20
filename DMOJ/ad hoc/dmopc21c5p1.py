n = int(input())
if n == 1:
    print(1)

elif n <= 4:
    print(-1)

else:
    out = []
    for i in range(1, n + 1):
        if i % 2 == 0 and i != 4:
            out.append(i)

    out.extend([4, 5])
    for i in range(1, n + 1):
        if i % 2 == 1 and i != 5:
            out.append(i)
    print(*out)
