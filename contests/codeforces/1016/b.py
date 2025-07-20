t = int(input())
for _ in range(t):
    num = list(input())
    new = ""
    ans = 0
    while num[-1] == '0':
        ans += 1
        num.pop()

    for c in num:
        if c != '0':
            ans += 1

    print(ans - 1)