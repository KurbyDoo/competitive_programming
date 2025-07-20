w, b = map(int, input().split())

works = False
if w + b == 0:
    works = True

string = "wbwbwwbwbwbw" * 20
substr = set()
for i in range(len(string)):
    for j in range(i, len(string)):
        substr.add(string[i:j + 1])
# print(substr)
for i in substr:
    if i.count('w') == w and i.count('b') == b:
        works = True

print("Yes" if works else "No")
