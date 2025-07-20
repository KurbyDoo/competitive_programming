n = int(input())
num = list(map(int, input().split()))
out = []
for i in range(n - 1):
    out.append(str(num[i] * num[i + 1]))

print(" ".join(out))