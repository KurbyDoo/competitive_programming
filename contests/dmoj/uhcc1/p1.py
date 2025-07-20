x, y, z = map(int, input().split())
l = int(input())
loc1 = 0
loc2 = 0
out = 0
while (loc1 < l and loc2 < l):
    if loc1 < loc2:
        loc1 += x
        if loc1 >= l:
            out = 1
            break
    
    else:
        loc2 += y
        if loc2 >= l:
            out = 2
            break

        loc1 += z
        if loc1 >= l:
            out = 1
            break
print(out)