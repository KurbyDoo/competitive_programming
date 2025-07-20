n, l = map(int, input().split())
pigs = list(map(int, input().split())) + [float('inf')]
pigs.reverse()

total = 0
elevator = []
while total <= l:
    elevator.append(pigs.pop())
    total += elevator[-1]

# print(*elevator)
biggest = max(elevator) 
pigs = [max(elevator)] + pigs
total -= max(elevator)
elevator.remove(max(elevator))

# print(*elevator)
asdas = False
while total + pigs[-1] <= l:
    elevator.append(pigs.pop())
    total += elevator[-1]
    asdas = True
# print(*elevator)

ans1 = len(elevator)

if asdas == False and min(pigs) + total <= l:
    ans1 += 1

print(ans1)
