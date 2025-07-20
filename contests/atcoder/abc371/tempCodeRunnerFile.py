n, m = map(int, input().split())
found = [False] * (n + 1)
for i in range(m):
  a, b = input().split()
  if b == 'F' or found[int(a)]: print("No")
  else:
    print("Yes")
    found[int(a)] = True
  