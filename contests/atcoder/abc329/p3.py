count = [0] * 26
n = int(input())
s = input()
length = 1
for i in range(1, n):
    if s[i] == s[i - 1]:
        length += 1

    else:
        count[ord(s[i - 1]) - ord('a')] = max(count[ord(s[i - 1]) - ord('a')], length)
        length = 1

count[ord(s[-1]) - ord('a')] = max(count[ord(s[-1]) - ord('a')], length)

# print(*count)
print(sum(count))