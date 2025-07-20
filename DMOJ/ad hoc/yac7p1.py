n = int(input())
nums = list(map(int, input().split()))
ans = 0
order = []
odds = []
odd_count = 0
even_count = 0
last_odd = -1
for index, a in enumerate(nums):
    if a % 2 == 0:
        even_count += 1
    if a % 2 == 1:
        odd_count += 1
        ans += a // 2
        last_odd = index
        odds.append(index + 1)

if odd_count > 0:
    back = odds.pop()
    order.append(back)
    for index, a in enumerate(nums):
        if a % 2 == 0:
            ans += (a // 2) - 1
            order.append(index + 1)

    order.extend(odds)

else:
    for index, a in enumerate(nums):
        ans += a // 2
        order.append(index + 1)

print(ans)
print(*order)
