n = int(input())
sheets = [list(map(int, input().split())) for _ in range(n)]
ans = 0
grid = [[0 for i in range(101)] for j in range(101)]
for x in range(101):
    for y in range(101):
        for a, b, c, d in sheets:
            if a <= x < b and c <= y < d:
                grid[x][y] += 1

for x in range(101):
    for y in range(101):
        if grid[x][y] >= 1:
            ans += 1

print(ans)