s = input().split("|")[1:-1]
ans = []
for i in s:
    ans.append(str(len(i)))
print(*ans)
