n, m = map(int, input().split())
s = input()
t = input()
pre = False
suf = False
if len(s) > len(t):
    print(3)

else:
    if t.find(s) == 0:
        pre = True

    if t[::-1].find(s[::-1]) == 0:
        suf = True


    if pre and suf:
        print(0)
    
    elif pre:
        print(1)

    elif suf:
        print(2)

    else:
        print(3)