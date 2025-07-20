from itertools import permutations
choices = []
for i in range(3):
    for j in range(3):
        choices.append((i, j))

grid = [[0 for i in range(3)] for j in range(3)]

for r in range(3):
    grid[r] = list(map(int, input().split()))

total = 0
disappointed = 0

def check_row(r, c):
    if all(found[r][i] for i in range(3)):
        nums = [grid[r][i] for i in range(3) if i != c]
        return nums[0] == nums[1]

def check_col(r, c):
    if all(found[i][c] for i in range(3)):
        nums = [grid[i][c] for i in range(3) if i != r]
        return nums[0] == nums[1]
    


for p in permutations(choices):
    total += 1
    found = [[False for c in range(3)] for r in range(3)]
    d = False
    for index, square in enumerate(p):
        found[square[0]][square[1]] = True
        if index < 2: continue
        if check_row(*square) or check_col(*square):
            d = True
            break
        
        if square[0] == square[1]:
            if all([found[i][i] for i in range(3)]):
                nums = [grid[i][i] for i in range(3) if i != square[0]]
                if nums[0] == nums[1]:
                    d = True
                    break

        if square[0] + square[1] == 2:
            if all([found[i][2 - i] for i in range(3)]):
                nums = [grid[i][2 - i] for i in range(3) if i != square[0]]
                if nums[0] == nums[1]:
                    d = True
                    break
    if d: disappointed += 1

print(1 - disappointed / total)