from collections import defaultdict
fact = defaultdict(int)

n = int(input())
fact[1] = 1
a = 1
b = 1
while a <= int(3 * 1e18):
    fact[a] = b
    b += 1
    a *= b

print(fact[n])