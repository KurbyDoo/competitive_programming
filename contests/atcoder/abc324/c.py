from collections import defaultdict
n, t = input().split()
n = int(n)
works = []
for asdsa in range(n):
    a = 0
    b = 0
    s = input()
    good = True
    error = False
    if len(s) == len(t):
        while (a < len(t)):
            if (t[a] != s[b]):
                if (not error):
                    error = True
                    a += 1
                    b += 1
                else:
                    good = False
                    break
            else:
                a += 1
                b += 1

    elif len(t) == len(s) + 1:
        while (a < len(t) and b < len(s)):
            # print(f"a = {t[a]} b = {s[b]}")
            if (t[a] != s[b]):
                if (not error):
                    a += 1
                    error = True
                else:
                    good = False
                    break
            else:
                a += 1
                b += 1

    elif len(t) == len(s) - 1:
        while (a < len(t) and b < len(s)):
            # print(f"a = {t[a]} b = {s[b]}")
            if (t[a] != s[b]):
                if (not error):
                    b += 1
                    error = True
                else:
                    good = False
                    break
            else:
                a += 1
                b += 1
    else:
        good = False
    if good:
        works.append(asdsa + 1)
print(len(works))
print(*works)
