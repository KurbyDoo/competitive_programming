t = int(input())
dp = [False] * 200010
dp[0] = True
cur_pos = 1
for _ in range(t):
    n, s1, s2 = input().split()
    s1, s2 = list(s1),list(s2)
    n = int(n)
    for i in range(n):
        print(i, "".join(s1), "".join(s2))
        if (s1[i] == s2[i]):
            dp[cur_pos + i] = dp[cur_pos + i - 1]
            # print("equal")
            continue

        if (s2[i] == "C"): continue
        if (s1[i] == "C" and s2[i] in "A"):
            dp[cur_pos + i] = dp[cur_pos + i - 1]
            s1[i] = s2[i]
            # print("rule 1/2")
            continue

        # if (s1[i] in "AC" and s2[i] in "B"):
        #     print("rule3")
        #     j = i + 1
        #     while(j < n and s1[j] == "B" and s2[j] == "B"):
        #         j += 1
        #     if j < n and s2[j] == "A":
        #         print("we")
        #         dp[cur_pos + i] = dp[cur_pos + i - 1]
        #         s1[i], s1[j] = s1[j], s1[i]
        #         continue

        if (s1[i] in "AC" and s2[i] in "B"):
            print("rule4")
            j = i + 1
            print(f"{j = }")
            oppB = 0
            while(j < n and (s1[j] in "BC") and not s2[j] == "A"):
                j += 1
                if s2[j] == "B": oppB += 1
                print(f"{j = }")
            if j < n and s1[j] in "BC" and oppB == j - i - 1:
                print("wor")
                dp[cur_pos + i] = dp[cur_pos + i - 1]
                s1[i], s1[j] = s1[j], s1[i]
                continue
            
            print("rule4.5")
            j = i + 1
            oppA = 0
            while(j < n and (s1[j] in "AC")):
                if (s2[j] == "A"):
                    oppA += 1
                j += 1
                # print(f"{j = }")
            if j < n and s1[j] in "BC" and oppA == j - i - 1:
                dp[cur_pos + i] = dp[cur_pos + i - 1]
                s1[i], s1[j] = s1[j], s1[i]
                continue

        if (s1[i] == "C" and s2[i] == "B"):
            dp[cur_pos + i] = dp[cur_pos + i - 1]
            s1[i] = s2[i]
            print("rule 1/B")
            continue
        # if (s1[i] == "A" and s2[i] == "B"):
        #     print("rule3")
        #     j = i
        #     while(j < n and s1[j] == "B"):
        #         j += 1
        #     if (j < n):
        #         if s2[j] == "C": s2[j] == "B"
        #         print("swap")
        #         s2[i], s2[j] = s2[j], s2[i]
        #         dp[cur_pos + i] = dp[cur_pos + i - 1]
        # print(f"{s1[i - 1:i + 1] = } {s2[i - 1:i + 1] = }")
        # if (i >= 1 and s1[i - 1:i + 1] in ["AB", "CB", "AC"] and s2[i - 1:i + 1] == "BA"):
            # dp[cur_pos + i] = dp[cur_pos + i - 2]
            # print("rule3")
    
    
    if dp[cur_pos + n - 1]:
        print("-----------Yes")
        # print("Yes")
    
    else:
        print("-----------No")
        # print("No")

    cur_pos += n
    dp[cur_pos - 1] = True

# 8
# 2 CB BA
# 2 CB BB
# 4 CBBA BBBA
# 3 ACB ABB
# 3 ACB BAB
# 3 CCB BAA
# 3 AAB BAA
# 3 ABB BBA
# 8 AAAABBBB BBBBAAAA