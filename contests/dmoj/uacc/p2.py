ans = 0
r = int(input())
r -= 2
if r >= 4:
    ans += 6 * (r // 4)
    r %= 4

if r == 0:
    ans += 1

if r == 1:
    ans += 4

if r == 2:
    ans += 5

if r == 3:
    ans += 6

print(ans)