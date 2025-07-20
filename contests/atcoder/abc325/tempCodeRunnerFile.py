                if grid[ny][nx] == "#" and not visited[ny][nx]:
                    visited[ny][nx] = True
                    dq.append((nx, ny))