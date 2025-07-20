n, m = map(int, input().split())
grid = [list(input()) for _ in range(n)]

for x in range(m):
    for y in range(n):
        if grid[y][x] != "W":
            continue

        xDir = [0, 0, 1, -1]
        yDir = [1, -1, 0, 0]

        for i in range(4):
            nextX = x + xDir[i]
            nextY = y + yDir[i]

            if 0 <= nextX < m and 0 <= nextY < n:
                if grid[nextY][nextX] == ".":
                    grid[nextY][nextX] = "C"

for row in grid:
    print("".join(row))
