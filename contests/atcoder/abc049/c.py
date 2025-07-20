s = input()
words = ["dream", "dreamer", "erase", "eraser"]
out = True
while s:
    ends = False
    for w in words:
        if s.endswith(w):
            ends = True
            s = s[:-len(w)]
            break
    # print(s)

    if not ends:
        out = False
        break

print("YES" if out else "NO")

