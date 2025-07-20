grid = [[0 for _ in range(9)] for _ in range(9)]
for y in range(9):
    grid[y] = list(map(int, input().split()))

works = "Yes"
for y in range(9):
    s = set()
    for x in range(9):
        s.add(grid[y][x])

    if len(s) != 9:
        works = "No"
    
for x in range(9):
    s = set()

    for y in range(9):
        s.add(grid[y][x])

    if len(s) != 9:
        works = "No"

for x1 in range(3):
    for y1 in range(3):
        s = set()
        for y2 in range(3):
            for x2 in range(3):
                s.add(grid[y1 * 3 + y2][x1 * 3 + x2])
        
        if len(s) != 9:
            works = "No"

print(works)
