n = int(input())
s = input()
if not "ABC" in s:
    print("-1")
else:
    print(s.find("ABC") + 1)