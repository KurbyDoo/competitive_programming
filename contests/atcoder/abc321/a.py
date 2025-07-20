n = input()
out = "Yes"
if (len(n) == 1):
    print("Yes")

else:
    for i in range(len(n) - 1):
        if int(n[i]) <= int(n[i + 1]):
            out = "No"
            break
    print(out)
