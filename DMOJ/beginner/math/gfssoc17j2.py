total = 0
for _ in range(6):
    total += int(input())

total /= 6
total += int(input())
print("yes" if total >= int(input()) else "no")