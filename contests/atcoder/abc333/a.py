sides = "ABCDE"
s1 = input()
s2 = input()

d1 = sides.index(s1[0]) - sides.index(s1[1])
d2 = sides.index(s2[0]) - sides.index(s2[1])
# print(d1, d2)
if abs(d1) == abs(d2) or abs(abs(d1) - 5) == abs(d2):
    print("Yes")

else:
    print("No")