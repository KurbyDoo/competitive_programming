s = input()
n = len(s)
lpsa = [0] * (n + 1)
mpsa = [0] * (n + 1)
spsa = [0] * (n + 1)
for i in range(n):
    if s[i] == "L": lpsa[i + 1] += 1
    if s[i] == "M": mpsa[i + 1] += 1
    if s[i] == "S": spsa[i + 1] += 1
    lpsa[i + 1] += lpsa[i]
    mpsa[i + 1] += mpsa[i]
    spsa[i + 1] += spsa[i]
l_count = lpsa[n]
m_count = mpsa[n]
s_count = spsa[n]
print((l_count - (lpsa[l_count])) + (m_count - (mpsa[l_count + m_count] - mpsa[l_count])) - min(mpsa[l_count], lpsa[l_count + m_count] - lpsa[l_count]))

# CBAACB -> AACBCB -> AABBCC = 3
# CBACAB -> AACCBB -> AABBCC = 2 + 2 - min(b in a, a in b)
# CBACAB -> AABCCB -> AABBCC = 3
