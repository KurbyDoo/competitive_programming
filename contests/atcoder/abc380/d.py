s = input()
rev = []
for c in s:
    if c.upper() == c: rev.append(c.lower())
    else: rev.append(c.upper())
rev = "".join(rev)
q = int(input())
for qi in list(map(int, input().split())):
    # pos = (qi - 1) % len(s)
    toggle = 0
    while qi > len(s):
        n = (qi - 1) // len(s)
        cnt = 0 if n == 0 else n.bit_length()
        # print(n, cnt)
        qi -= len(s) * (1 << (cnt - 1))
        toggle += 1

    print(s[qi - 1] if toggle % 2 == 0 else rev[qi - 1], end=" ")
