from collections import deque
h, w = map(int, input().split())
grid = [list(input()) for _ in range(h)]
visited = [[False for _ in range(w)] for _ in range(h)]

def search(x, y):
    count = 0
    dq = deque([(x, y)])
    visited[y][x] = True
    while dq:
        rx, ry = dq.popleft()
        # print(f"at {rx} {ry}")
        dx = [0, 0, 1, 1, 1, -1, -1, -1]
        dy = [1, -1, 1, 0, -1, 1, 0, -1]
        for cx, cy in zip(dx, dy):
            nx = rx + cx
            ny = ry + cy
            if 0 <= nx < w and 0 <= ny < h:
                if grid[ny][nx] == "#" and not visited[ny][nx]:
                    visited[ny][nx] = True
                    dq.append((nx, ny))

    return count

count = 0
for x in range(w):
    for y in range(h):
        if visited[y][x]: continue
        if grid[y][x] != "#": continue
        count += 1
        search(x, y)
print(count)
