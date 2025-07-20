n, target = map(int, input().split())

a = list(map(int, input().split()))
c = a.copy()

a.append(0)
a.sort()
c.sort()
to_add = target - sum(c) + c[-1] + c[0]
c.append(to_add)
c.sort()

if sum(a) - a[0] - a[-1] >= target:
    print(0)
elif (to_add > 100 or to_add > c[-1]): 
    print(-1)
elif sum(c) - c[0] - c[-1] >= target:
    print(to_add)
else: print(-1)

# print(c, to_add, sum(c[1:-1]))