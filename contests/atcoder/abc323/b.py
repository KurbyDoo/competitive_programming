n = int(input())
thing = []
for i in range(n):
    wins = input().count("x")
    thing.append((wins, i))

thing.sort()
for a, b in thing:
    print(b + 1)