m = int(input())

out = []
i = 20
while i >= 0:
  if 3 ** i <= m:
    out.append(i)
    m -= 3 ** i
  else:
    i -= 1
print(len(out))
print(*out)