b = int(input())
num = 1
thing = num * num
while thing < b:
    num += 1
    thing = 1
    for _ in range(num):
        thing *= num
        if (thing > b): break

if thing == b:
    print(num)

else: print("-1")
