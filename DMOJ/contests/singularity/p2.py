import sys
n = int(input())
s = input()

if (s[0] != s[-1]):
    print(n)
    sys.exit()

first_count = 0
for i in range(n):
    if s[i] != s[-1]:
        break
    first_count += 1

s = s[first_count:] + s[:first_count]
ans = 0
past = ""
for c in s:
    if c == past:
        ans += 1
    past = c

# print(s)
print(n - ans)

# 7
# accbbca
# 10
# abbaaacdda
