n = int(input())
q = list(input())
front = []
back = ""
for i in q:
    if not front or i <= front[-1]:
        front.append(i)
    else:
        back += i
out = ""
while front:
    out += front.pop()
print(out + back)
