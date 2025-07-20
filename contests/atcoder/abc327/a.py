n = int(input())
s = input()
out = "No"
for i in range(n - 1):
    if (s[i] == 'a' and s[i + 1] == 'b'): out = "Yes"
    if (s[i] == 'b' and s[i + 1] == 'a'): out = "Yes"
print(out)