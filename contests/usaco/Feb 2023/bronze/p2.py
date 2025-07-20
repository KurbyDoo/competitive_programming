t = int(input())

for _ in range(t):
    input()
    gridSize = int(input())
    grid = []
    possible = [[False for _ in range(gridSize)] for _ in range(gridSize)]
    for i in range(gridSize):
        grid.append(list(input()))

    stampSize = int(input())
    stamp = []
    for i in range(stampSize):
        stamp.append(list(input()))

    for x in range(gridSize - stampSize + 1):
        for y in range(gridSize - stampSize + 1):

            for rotate in range(4):
                p = True
                for xOff in range(stampSize):
                    for yOff in range(stampSize):
                        if rotate == 0:
                            stampX = xOff
                            stampY = yOff

                        elif rotate == 1:
                            stampX = stampSize - 1 - yOff
                            stampY = xOff

                        elif rotate == 2:
                            stampX = stampSize - 1 - xOff
                            stampY = stampSize - 1 - yOff

                        elif rotate == 3:
                            stampX = yOff
                            stampY = stampSize - 1 - xOff

                        if stamp[stampX][stampY] == ".":
                            continue

                        if grid[x + xOff][y + yOff] == ".":
                            p = False
                            break

                    if p == False:
                        break

                if p:
                    # print(f"\nstamp at {x, y} rotation {rotate}")
                    for xOff in range(stampSize):
                        for yOff in range(stampSize):
                            if rotate == 0:
                                stampX = xOff
                                stampY = yOff

                            elif rotate == 1:
                                stampX = stampSize - 1 - yOff
                                stampY = xOff

                            elif rotate == 2:
                                stampX = stampSize - 1 - xOff
                                stampY = stampSize - 1 - yOff

                            elif rotate == 3:
                                stampX = yOff
                                stampY = stampSize - 1 - xOff

                            if stamp[stampX][stampY] == ".":
                                # print(
                                # f"not marking {y + yOff, x + xOff} stamp {stampY, stampX}")
                                continue

                            # print(
                            #     f"marking {y + yOff, x + xOff} stamp {stampY, stampX}")
                            possible[x + xOff][y + yOff] = True
    works = True
    for x in range(gridSize):
        for y in range(gridSize):
            if grid[x][y] == "*":
                if not possible[x][y]:
                    works = False

    print("YES" if works else "NO")
    # for x in range(gridSize):
    #     for y in range(gridSize):
    #         print(possible[x][y], end=" ")

    #     print()

    # for x in range(gridSize):
    #     for y in range(gridSize):
    #         print(grid[x][y], end=" ")

    #     print()


# 1

# 3
# **.
# .**
# ..*
# 2
# .*
# *.

# 3

# 5
# *****
# *...*
# *...*
# *...*
# *****
# 2
# *.
# ..

# 4
# .**.
# *.**
# ****
# .**.
# 2
# **
# *.

# 4
# .**.
# ****
# ****
# .**.
# 1
# .


# 1

# 4
# .**.
# *..*
# ****
# .**.
# 2
# **
# *.

# 1

# 2
# **
# **
# 2
# .*
# *.

# 4

# 4
# ...*
# .***
# .***
# ****
# 4
# ...*
# .***
# .***
# ****

# 4
# *...
# ***.
# ***.
# ****
# 4
# ...*
# .***
# .***
# ****

# 4
# ****
# ***.
# ***.
# *...
# 4
# ...*
# .***
# .***
# ****

# 4
# ****
# .***
# .***
# ...*
# 4
# ...*
# .***
# .***
# ****


# 1

# 2
# .*
# ..
# 2
# **
# ..

# 1

# 3
# ...
# ...
# ..*
# 2
# *.
# ..


# 1

# 3
# ***
# *.*
# ***
# 2
# *.
# *.

