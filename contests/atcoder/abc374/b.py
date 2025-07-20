s = input()
t = input()

if s == t:
    print("0")

else:
    length = min(len(s), len(t))
    wrong = -1

    for i in range(length):
        if s[i] != t[i]:
            wrong = i + 1
            break
        
    if wrong == -1:
        wrong = length + 1

    print(wrong)
