from collections import deque
import sys
input = sys.stdin.readline
r, c = map(int, input().split())

graph = [list(input()) for _ in range(r)]
timeTravel = [[-1 for _ in range(c)] for _ in range(r)]
timeFlooded = [[999 for _ in range(c)] for _ in range(r)]

start = None
end = None

q = deque([])
for x in range(c):
    for y in range(r):
        if graph[y][x] == "S":
            start = (x, y)

        if graph[y][x] == "D":
            end = (x, y)

        if graph[y][x] == "*":
            timeFlooded[y][x] = 0
            q.append((x, y, 0))

        if graph[y][x] == "X":
            timeTravel[y][x] = 999
            timeFlooded[y][x] = 999



while q:
    curX, curY, time = q.popleft()

    xDir = [0, 0, -1, 1]
    yDir = [1, -1, 0, 0]
    for i in range(4):
        if 0 <= curX + xDir[i] < c  and 0 <= curY + yDir[i] < r:
            if graph[curY + yDir[i]][curX + xDir[i]] in "S." and timeFlooded[curY + yDir[i]][curX + xDir[i]] == 999:
                timeFlooded[curY + yDir[i]][curX + xDir[i]] = time + 1
                q.append((curX + xDir[i], curY + yDir[i], time + 1))

q.append((start[0], start[1], 0))
timeTravel[start[1]][start[0]] = 0
while q:
    curX, curY, time = q.popleft()

    xDir = [0, 0, -1, 1]
    yDir = [1, -1, 0, 0]
    for i in range(4):
        if 0 <= curX + xDir[i] < c  and 0 <= curY + yDir[i] < r:
            if graph[curY + yDir[i]][curX + xDir[i]] in ".D" and timeTravel[curY + yDir[i]][curX + xDir[i]] == -1:
                timeTravel[curY + yDir[i]][curX + xDir[i]] = time + 1
                q.append((curX + xDir[i], curY + yDir[i], time + 1))

# for row in timeFlooded:
#     print(row)

# for row in timeTravel:
#     print(row)

visited = [[False for _ in range(c)] for _ in range(r)]

q.append((start[0], start[1], 0))
visited[start[1]][start[0]] = True
while q:
    curX, curY, time = q.popleft()
    # print(f"at {curX, curY}")

    if (curX, curY) == end:
        print(time)
        sys.exit()

    xDir = [0, 0, -1, 1]
    yDir = [1, -1, 0, 0]
    for i in range(4):
        nextX = curX + xDir[i]
        nextY = curY + yDir[i]
        if 0 <= nextX < c  and 0 <= nextY < r:
            if (nextX, nextY) == end or (timeTravel[nextY][nextX] < timeFlooded[nextY][nextX] and not visited[nextY][nextX]):
                visited[nextY][nextX] = True
                q.append((nextX, nextY, time + 1))

print("KAKTUS")

# 5 5
# D....
# .....
# .....
# ...S.
# *...*
# 5 5
# D....
# .....
# .....
# ...S.
# ...**

# 5 5
# D....
# XXXX.
# X....
# ...S.
# .....