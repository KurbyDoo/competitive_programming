s = input()
if len(s) >= 3:
    if s[len(s) - 3:] == "san":
        print("Yes")
    
    else:
        print("No")
else:
    print("No")