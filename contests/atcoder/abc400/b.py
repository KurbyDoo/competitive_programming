n, m = map(int, input().split())
t = 0
for i in range(0, m + 1):
    t += pow(n, i)

    if t > 10**9:
        t = 'inf'
        break

print(t)