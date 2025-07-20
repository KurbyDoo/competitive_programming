from collections import deque
r, c = map(int, input().split())

startY, startX = map(int, input().split())
officeY, officeX = map(int, input().split())

grid = [list(input()) for _ in range(r)]
teleport = [[False for _ in range(c)] for _ in range(r)]
visited = [[False for _ in range(c)] for _ in range(r)]


t = int(input())
for _ in range(t):
    a, b = map(int, input().split())
    teleport[a][b] = True

q = deque([(startX, startY, 0)])

visited[startY][startX] = True
officeDist = 100000000
minDist = 100000000
while q:
    curX, curY, curD = q.popleft()
    if (curX, curY) == (officeX, officeY):
        officeDist = min(officeDist, curD)
        continue

    if teleport[curY][curX] == True:
        minDist = min(minDist, curD)

    xOff = [0, 0, 1, -1]
    yOff = [1, -1, 0, 0]
    for xO, yO in zip(xOff, yOff):
        newX = curX + xO
        newY = curY + yO
        if 0 <= newX < c and 0 <= newY < r and grid[newY][newX] != "X" and not visited[newY][newX]:
            q.append([newX, newY, curD + 1])
            visited[newY][newX] = True

print(max(officeDist - minDist, 0))
