m, k = map(int, input().split())
doubles = m // 2
single = m % 2
total = pow(2, doubles, int(1e9 + 7))
if single == 1:
    total *= (doubles + 1)
print(3 * doubles + 3 * single)
print(total)