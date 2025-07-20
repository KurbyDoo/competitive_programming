import sys, re
input = sys.stdin.readline
for _ in range(5):
    rows, cols = map(int, input().split())

    marked = [[False for _ in range(cols)] for _ in range(rows)]
    grid = []
    for _ in range(rows):
        grid.append(input())

    n = int(input())
    words = [re.sub(r'[^A-Z]', '', input()) for _ in range(n)]


    def check(startX, startY, word):
        wordLength = len(word)

        xDir = [0, 1, 1, 1, 0, -1, -1, -1]
        yDir = [1, 1, 0, -1, -1, -1, 0, 1]
        for i in range(8):
            temp = ""
            for j in range(wordLength):
                if (0 <= xDir[i] * j + startX < cols and 0 <= yDir[i] * j + startY < rows):
                    temp += grid[yDir[i] * j + startY][xDir[i] * j + startX]

            if (temp == word):
                # print(f"found word {word}")
                for j in range(wordLength):
                    marked[yDir[i] * j + startY][xDir[i] * j + startX] = True

            # print(f"word = {temp, word}")


    for w in words:
        for x in range(cols):
            for y in range(rows):
                check(x, y, w)

    # check(0, 0, words[0])


    for y in range(rows):
        for x in range(cols):
            if not marked[y][x]:
                print(grid[y][x], end="")

    print("")

# for y in range(cols):
#     for x in range(rows):
#         print("X" if marked[y][x] else "_", end="")

#     print("")
# CHOCOLATEORIGINATESFROMTHESEEIDRSCOEFETACHEMRTEPHAEIOMBREOAMACACAOTREE
# CHOCOLATEORIGINATESFROMTHESEEDSOFTHETHEOBROAMACACAOTREE
# 
# 17 17
# KLIMTSEINWORBCHOC
# CGOLYNASEMISWEETT
# EHNCSDENETEEWSNUO
# RCIIOENIIGFILLING
# SIOPKCLADNABFTESE
# KFRNSAOFCEIOOMCTV
# NRHEFDBAFTRSOEHEI
# ICATAERTTUIGDDOGT
# RORDSNCECCRONSCNC
# DOWEFTRTEUTTUIOII
# GKHTASPCIRPOHFLDD
# NIIEWMRUEOICOTADD
# IETESEPSRCNNAHTUA
# CSESAESIIYDEBKIPO
# ITIMBERLEUSAROEAM
# AWFUDGECEARCAYRSO
# SUGARDTESSUOMRSEE
# 1
# KLIM

# 2 3
# ABC
# EFG
# 3
# AF
# CG
# EFG