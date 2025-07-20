n, h, x = map(int, input().split())
potions = list(map(int, input().split()))

ans = (-1, 99999)
for i in range(len(potions)):
    if potions[i] + h >= x and potions[i] < ans[1]:
        ans = (i + 1, potions[i])

print(ans[0])