n, t = map(int, input().split())

curDay = 0
surPlus = 0
total = 0
for _ in range(n):
    a, b = map(int, input().split())
    if surPlus > ((a - 1) - curDay):
        total += (a - 1) - curDay
        surPlus -= (a - 1) - curDay

    else:
        total += surPlus
        surPlus = 0
    surPlus += b
    curDay = a - 1

a, b = (t, 0)
if surPlus > (a - curDay):
    total += a - curDay
    surPlus -= a - curDay

else:
    total += surPlus
    surPlus = 0

print(total)