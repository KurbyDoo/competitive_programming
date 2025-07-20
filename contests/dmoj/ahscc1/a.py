avg = int(input())
num = int(input())
work = False
for i in range(101):
    if (avg * num + i) / (num + 1) >= 80:
        print(i)
        work = True
        break
if not work:
    print("-1")
