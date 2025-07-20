import sys
input = sys.stdin.readline

rows = int(input())
columns = int(input())

grid = [list(input())[:-1] for _ in range(rows)]
maxX = 0
maxY = 0
minX = 0
minY = 0

totalXOffset = 0
totalYOffset = 0
directions = []
curDir = 120000
xOff = [1, 0, -1, 0]
yOff = [0, 1, 0, -1]
for i in range(int(input())):
    d = input()[:-1]
    if d == "L":
        curDir = curDir - 1

    elif d == "R":
        curDir = curDir + 1

    elif d == "F":
        totalXOffset += xOff[curDir % 4]
        totalYOffset += yOff[curDir % 4]

        maxX = max(maxX, totalXOffset)
        maxY = max(maxY, totalYOffset)
        minX = min(minX, totalXOffset)
        minY = min(minY, totalYOffset)

    directions.append(d)

print(f"{totalXOffset}, {totalYOffset}")

maxQx = [maxX, -maxY, -maxX, maxY]
maxQy = [maxY, maxX, -maxY, -maxX]

minQx = [minX, -minY, -minX, minY]
minQy = [minY, minX, -minY, -minX]

for row in range(rows):
    for column in range(columns):
        for direction in range(4):
            # print(f"trying {column, row} facing {direction}")
            currentX = column
            currentY = row
            currentDirection = direction + 120000

            if not (0 <= currentX + maxQx[currentDirection % 4] < columns and 0 <= currentY + maxQy[currentDirection % 4] < rows):
                continue
            
            if not (0 <= currentX + minQx[currentDirection % 4] < columns and 0 <= currentY + minQy[currentDirection % 4] < rows):
                continue
            if grid[currentY][currentX] == "X":
                continue

            # print(f"offset {currentX + (totalXOffset * xQuad[currentDirection % 4]), currentY + (totalYOffset * yQuad[currentDirection % 4])}")
            # print("did not pass")

            for step in directions:
                if step == "R":
                    currentDirection += 1

                elif step == "L":
                    currentDirection -= 1

                elif step == "F":
                    currentX += xOff[currentDirection % 4]
                    currentY += yOff[currentDirection % 4]

                    if not (0 <= currentX < columns and 0 <= currentY < rows):
                        break

                    if grid[currentY][currentX] == "X":
                        break

            if currentX >= 0 and currentY >= 0:
                if currentX < columns and currentY < rows:
                    if grid[currentY][currentX] != "X":
                        grid[currentY][currentX] = "*"

for i in grid:
    print("".join(i))
