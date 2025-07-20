a, m, l, r = map(int, input().split())
l -= a
r -= a
ans = -1
# print(l, r)
if l > 0:
    ans = (r // m) - ((l - 1) // m)

elif r < 0:
    # print((r + 1) // m, (l // m))
    ans = (abs(l) // m) - (abs(r + 1) // m)
else:
    ans = (r // m) + (abs(l) // m) + 1
print(ans)