n, m = map(int, input().split())
grid = [[-1] * m for i in range(n)]
if n == 1 and m == 1:
    print("1\n1")

elif n == 1:
    print("2")
    out = [0] * m
    for i in range(m):
        out[i] = i % 2 + 1
    print(*out)

elif m == 1:
    print("2")
    for i in range(n):
        print(i % 2 + 1)

else:
    print("4")
    for i in range(n):
        for j in range(m):
            if i % 2 == 0:
                grid[i][j] = j % 2 + 1
            
            else:
                grid[i][j] = j % 2 + 3
        print(*grid[i])