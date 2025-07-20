n, m = map(int, input().split())
s = input()

best = 0
logo = 0
normal = 0
for i in range(n):
    if s[i] == '0':
        logo = best
        normal = m

    elif s[i] == '1':
        if normal > 0:
            normal -= 1

        else:
            if logo > 0:
                logo -= 1

            else:
                best += 1

    elif s[i] == '2':
        if logo > 0:
            logo -= 1
        else:
            best += 1

print(best)

        
