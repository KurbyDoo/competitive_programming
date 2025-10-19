rn, gn, bn = map(int, input().split())
ro, go, bo = map(int, input().split())
rg, gb = map(int, input().split())
ans = 0
if rg >= max(rn - ro, 0):
    ans += max(rn - ro, 0)
    rg -= max(rn - ro, 0)
else:
    ans = float("inf")
if gb >= max(0, bn - bo):
    ans += max(0, bn - bo)
    gb -= max(0, bn - bo)
else:
    ans = float("inf")

if rg + gb >= max(0, gn - go):
    ans += max(0, gn - go)
else:
    ans = float("inf")

print("-1" if ans == float("inf") else ans)