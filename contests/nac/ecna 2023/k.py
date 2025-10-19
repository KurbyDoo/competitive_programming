from collections import defaultdict
n = int(input())
words = [input() for _ in range(n)]
mapping = defaultdict(int)
for word in words:
    for i in range(len(word) - 1):
        new_word = word[:i] + "**" + word[i + 2:]
        mapping[new_word] += 1

ans = 0
for val in mapping:
    print(val, mapping[val])
        