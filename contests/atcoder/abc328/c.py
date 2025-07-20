n, q = map(int, input().split())
psa = [0] * (n + 1)
s = input()
for c in range(2, n + 1):
    if (s[c - 1] == s[c - 2]):
        psa[c] += 1

    psa[c] += psa[c - 1]

for i in range(q):
    l, r = map(int, input().split())
    print(psa[r] - psa[l])

# print(*psa)