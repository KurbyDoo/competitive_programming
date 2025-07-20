import sys

n, m, rows, cols = map(int, input().split())

alpha = list("abcdefghijklmnopqrstuvwxyz")
grid = [[alpha[(x + y) % 25 + 1] for x in range(m)] for y in range(n)]

if (rows == 0 and cols == 0):
    for r in grid:
        print("".join(r))

elif (n == rows and m == cols):
    for i in range(n):
        print("a" * m)

elif (n == rows):
    if (cols == 0):
        for i in range(n):
            print(alpha[i % 26] * m)

    elif (m % 2 == 0 and cols % 2 == 1):
        print("IMPOSSIBLE")

    else:
        if ((cols != m - 1 or n % 2) and not (cols == 1 and m % 2 == 0)):
            for i in range(n):
                if i < n // 2:
                    print(alpha[i % 26] * m)

                else:
                    print(alpha[i % 26] * ((m - cols) // 2), end="")
                    print(alpha[((n // 2) - ((i % 26) - (n // 2)) - (1 - (n % 2))) % 26] * (cols // 2), end="")
                    print(alpha[((n // 2) - ((i % 26) - (n // 2)) - (1 - (n % 2))) % 26] * (cols % 2), end="")
                    print(alpha[i % 26] * ((m - cols) % 2), end="")
                    print(alpha[((n // 2) - ((i % 26) - (n // 2)) - (1 - (n % 2))) % 26] * (cols // 2), end="")
                    print(alpha[i % 26] * ((m - cols) // 2))
        else:
            print("IMPOSSIBLE")

elif (m == cols):
    if (rows == 0):
        s = ""
        for i in range(m):
            s += alpha[i % 26]


        for i in range(n):
            print(s[::1])

    elif (n % 2 == 0 and rows % 2 == 1):
        print("IMPOSSIBLE")

    else:
        if ((rows != n - 1 or m % 2) and not (rows == 1 and n % 2 == 0)):
            s = ""
            midS = ""
            for i in range(m):
                s += alpha[i % 26]

                if i < m // 2:
                    midS += alpha[i % 26]

                else:
                    midS += alpha[(m // 2) - ((i % 26) - (m // 2)) - (1 - (m % 2))]

            for i in range((n - rows) // 2):
                print(s)

            for i in range(rows // 2):
                print(midS)

            for i in range((n - rows) % 2):
                print(s)

            for i in range(rows % 2):
                print(midS)

            for i in range(rows // 2):
                print(midS)

            for i in range((n - rows) // 2):
                print(s)
                
        else:
            print("IMPOSSIBLE")

else:
    for i in range(rows):
        for j in range(m):
            grid[i][j] = 'a'

    for i in range(cols):
        for j in range(n):
            grid[j][i] = 'a'
    
    for r in grid:
        print("".join(r))
    