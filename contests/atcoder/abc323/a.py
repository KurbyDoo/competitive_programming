s = input()
out = "Yes"
for i in range(16):
    if i % 2 == 1 and s[i] == "1":
        out = "No"

print(out)