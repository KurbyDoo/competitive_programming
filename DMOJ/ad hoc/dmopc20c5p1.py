s = input()
t = input()
same = 0
for i in range(min(len(s), len(t))):
    if (s[i] != t[i]): break 
    same += 1
print((len(s) - same) + (len(t) - same))