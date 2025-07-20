from collections import defaultdict
in_c = defaultdict(bool)
n = int(input())
a = list(map(int, input().split()))
m = int(input())
b = list(map(int, input().split()))
l = int(input())
c = list(map(int, input().split()))
q = int(input())
x = list(map(int, input().split()))

for i in c:
    in_c[i] = True

for x_i in x:
    works = False
    for a_i in a:
        for b_i in b:
            if in_c[x_i - a_i - b_i]:
                works = True
            
            if works: break
        if works: break
    print("Yes" if works else "No")

