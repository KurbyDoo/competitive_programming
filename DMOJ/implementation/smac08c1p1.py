s = list(input()) + list(input())

alpha = list("abcdefghijklmnopqrstuvwxyz")
number = [0 for _ in range(26)]

for c in s:
    number[alpha.index(c)] += 1

works = True
for n in number:
    if n % 2:
        works = False

print("Yes" if works else "No")
