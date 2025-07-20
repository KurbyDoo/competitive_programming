import sys
input = sys.stdin.readline

n = int(input())

for _ in range(n):
    
    item = input().lower().split()

    if item[0][-2:] == "'s":
        print("Set")
        continue

    if item[0] == "damaged":
        print("Normal")
        continue

    if len(item) == 2:
        if item[-2] == "of":
            print("Rare")
            continue
        print("Not sure, take anyways")
        continue

    if len(item) == 1 or len(item) > 4:
        print("Normal")
        continue

    if item[-2] == "of":
        print("Magic")
        continue

    print("Normal")
