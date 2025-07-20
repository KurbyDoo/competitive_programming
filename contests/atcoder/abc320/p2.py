s = input()
n = len(s)
ans = 0
for size in range(1, n + 1):
    works = True
    for l in range(n - size + 1):
        r = l + size
        if s[l:r] == s[l:r][::-1]:
            ans = size
            break
print(ans)