from collections import deque
import sys
input = sys.stdin.readline

maxCost = int(input())
rows = int(input())
cols = int(input())

visited = [[False for _ in range(cols)] for _ in range(rows)]

grid = [list(input()[:-1]) for _ in range(rows)]


def bfs(startX, startY):
    size = 0
    q = deque([(startX, startY)])
    visited[startY][startX] = True
    while q:
        curX, curY = q.popleft()
        size += 1

        xDir = [1, -1, 0, 0]
        yDir = [0, 0, 1, -1]
        for i in range(4):
            nextX = curX + xDir[i]
            nextY = curY + yDir[i]
            if not (0 <= nextX < cols and 0 <= nextY < rows):
                continue
            if (grid[nextY][nextX] == "I"):
                visited[nextY][nextX] = True
            if (visited[nextY][nextX]):
                continue

            visited[nextY][nextX] = True
            grid[nextY][nextX] = " " + str(size) + " "
            q.append((nextX, nextY))

    return size


sizes = []
for y in range(rows):
    for x in range(cols):
        if (visited[y][x]):
            continue
        if grid[y][x] == "I":
            visited[y][x] = True

        else:
            sizes.append(bfs(x, y))

sizes.sort()
used = 0
count = 0

while sizes and used + sizes[-1] <= maxCost:
    # print(sizes)
    used += sizes.pop()
    count += 1

print(f"{count} room{'s' if count != 1 else ''}, {maxCost - used} square metre(s) left over")
