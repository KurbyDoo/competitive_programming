m, k = map(int, input().split())
mod = int(1e9 + 7)
if k == 0 or m % 2 == 0:
    doubles = m // 2
    single = m % 2
    total = pow(2, doubles, mod)
    if single == 1:
        total = ((total % mod) * ((doubles + 1) % mod)) % mod
    print(3 * doubles + 3 * single)
    print(total)

elif k == 1:
    a, b = map(int, input().split())
    if a != 2 or b % 2 == 1:
        doubles = m // 2
        single = m % 2
        total = pow(2, doubles, mod)
        if single == 1:
            total = ((total % mod) * ((doubles + 1) % mod)) % mod
        print(3 * doubles + 3 * single)
        print(total)

    else:
        doubles = (m - 3) // 2
        total = pow(2, doubles + 1, mod)
        print(3 * doubles + 4)
        print(total)
