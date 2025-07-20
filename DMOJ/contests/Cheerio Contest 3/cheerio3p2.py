import sys
input = sys.stdin.readline

n = int(input())
s = input()

score = 0
opponentAmmo = 0
ourAmmo = 0
actions = ""
for i in range(n):
    opponentAction = s[i]

    if opponentAction == "F" and opponentAmmo > 0:
        opponentAmmo -= 1
        actions += "B"
        continue

    if opponentAction == "B":
        ourAmmo += 1
        actions += "R"
        continue
    
    if opponentAction == "R":
        opponentAmmo += 1

    if ourAmmo > 0:
        ourAmmo -= 1
        score += 1
        actions += "F"
        continue

    ourAmmo += 1
    actions += "R"

# print(actions)
print(score)
