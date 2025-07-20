t = int(input())
for _ in range(t):
    n, s1, s2 = input().split()
    n = int(n)
    ss1 = []
    ss2 = []
    last = 0
    possible = True
    for i in range(n):
        if s2[i] == "C":
            if (s1[i] == "C"):
                ss1.append(s1[last:i])
                ss2.append(s2[last:i])
                last = i + 1
            else:
                possible = False
                break
    
    if not possible:
        print("No")
        continue
    ss2.append(s2[last:i + 1])
    ss1.append(s1[last:i + 1])
    # print(ss1, ss2)
    for s1, s2 in zip(ss1, ss2):
        # print(f"{s1 = } {s2 = }")
        s1a = s1.count('A')
        s2a = s2.count('A')
        s1b = s1.count("B")
        s2b = s2.count("B")
        s1c = s1.count("C")
        # print(f"{s1a} - {s2a} + {s1b} - {s2b} = {s1c}")
        if s1a > s2a or s1b > s2b:
            possible = False
            break

        aDiff = s2a - s1a
        bDiff = s2b - s1b
        if aDiff + bDiff != s1c:
            possible = False
            break
        
        s1 = list(s1)
        s2 = list(s2)
        for i in range(len(s1)):
            if s1[i] == "C":
                if aDiff:
                    s1[i] = "A"
                    aDiff -= 1
                else:
                    s1[i] = "B"
            
        # print(s1, s2)
        s1p, s2p = 0, 0
        while (s1p < len(s1) and s2p < len(s2)):
            # print(s1p, s2p, s1[s1p], s2[s2p])
            while s1p < len(s1) and s1[s1p] != "A":
                s1p += 1

            while s2p < len(s2) and s2[s2p] != "A":
                s2p += 1

            if s1p > s2p:
                possible = False
                break
            s1p += 1
            s2p += 1


    if possible:
        print("Yes")
    
    else:
        print("No")


# 9
# 2 CB BA
# 2 CB BB
# 4 CBBA BBBA
# 3 ACB ABB
# 3 ACB BAB
# 3 CCB BAA
# 3 AAB BAA
# 3 ABB BBA
# 8 AAAABBBB BBBBAAAA