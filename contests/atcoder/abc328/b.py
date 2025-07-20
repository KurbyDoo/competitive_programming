n = int(input())
days = list(map(int, input().split()))
ans = 0
for i in range(1, n + 1):
    d = days[i - 1]
    for day in range(1, d + 1):
        thing = str(i) + str(day)
        works = True
        for j in range(len(thing)):
            if thing[j] != thing[0]:
                works = False
        if works:
            # print(i, day)
            ans += 1
print(ans)