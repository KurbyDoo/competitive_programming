n, k = map(int, input().split())
removed = [False] * (n + 1)
for i in list(map(int, input().split())):
    removed[i] = True

total_pairs = (n * 2 - k) // 2
socks = []
for i in range(1, n + 1):
    socks.append(i)
    if not removed[i]:
        socks.append(i)

a = [float('inf')] * (n * 2 - k + 1)
b = [float('inf')] * (n * 2 - k + 1)

a[0] = 0
for i in range(2, n * 2 - k + 1):
    a[i] = min(a[i], a[i - 2] + abs(socks[i - 2] - socks[i - 1]))

for i in range(3, n * 2 - k + 1):
    b[i] = min(b[i], b[i - 2] + abs(socks[i - 2] - socks[i - 1]))
    b[i] = min(b[i], a[i - 3] + abs(socks[i - 3] - socks[i - 2]))
    b[i] = min(b[i], a[i - 3] + abs(socks[i - 3] - socks[i - 1]))
    b[i] = min(b[i], a[i - 3] + abs(socks[i - 1] - socks[i - 2]))

# print(*a)
# print(*b)
if k % 2 == 0:
    print(a[n * 2 - k])

else:
    print(min(a[-2], b[-1]))