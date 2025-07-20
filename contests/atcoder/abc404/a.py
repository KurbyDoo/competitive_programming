s = input()
found = [False for _ in range(26)]
for c in s:
    found[ord(c) - ord('a')] = True

for i in range(26):
    if not found[i]:
        print(chr(i + ord('a')))
        break