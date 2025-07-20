grid = []
for i in range(8):
    grid.append(list(input()))

best_path = []
path = []

def find_max(cur_x, cur_y):
    # print(f"at {cur_x} {cur_y}")
    x_dir = [1, 1, -1, -1]
    y_dir = [1, -1, -1, 1]
    best = 0
    for cx, cy in zip(x_dir, y_dir):
        if (cur_x + cx < 0 or cur_x + cx >= 8 or cur_y + cy < 0 or cur_y + cy >= 8): continue
        if (grid[cur_y + cy][cur_x + cx] != "B"): continue
        big_x = cx * 2
        big_y = cy * 2
        if (cur_x + big_x < 0 or cur_x + big_x >= 8 or cur_y + big_y < 0 or cur_y + big_y >= 8): continue
        if (grid[cur_y + big_y][cur_x + big_x] != "."): continue

        grid[cur_y + cy][cur_x + cx] = "."
        path.append((cur_x + big_x, cur_y + big_y))
        test = find_max(cur_x + big_x, cur_y + big_y) + 1
        if (test > best):
            best = test
            # best_path.copy(path)
            
        grid[cur_y + cy][cur_x + cx] = "B"

    return best

ans = 0
for x in range(8):
    for y in range(8):
        if (grid[y][x] == "A"):
            ans = max(find_max(x, y), ans)
        
print(ans)
# print(best_path)