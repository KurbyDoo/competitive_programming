thing = input()
found = True
for i in thing:
    if i == "|": 
        found = not found
    elif found:
        print(i,end="")