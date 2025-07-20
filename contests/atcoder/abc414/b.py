n = int(input())
ans = ""
tot = 0
for i in range(n):
    c, l = input().split()
    tot += int(l)
    if tot > 100:
        ans = "Too Long"
        break
    ans += c * int(l)
print(ans)