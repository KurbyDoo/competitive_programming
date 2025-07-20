n, m, k = map(int, input().split())
for _ in range(n):
  row = list(input())
  a_blocked = [False] * m
  b_blocked = [False] * m

  rem = 0
  for i in range(m):
    if rem > 0:
      b_blocked[i] = True
      rem -= 1

    if row[i] == "A":
      rem = k
  
  rem = 0
  for i in range(m - 1, -1, -1):
    if rem > 0:
      a_blocked[i] = True
      rem -= 1

    if row[i] == "B":
      rem = k

  out = ""
  for i in range(m):
    if row[i] == "A": out += "N" if a_blocked[i] else "Y"
    elif row[i] == "B": out += "N" if b_blocked[i] else "Y"
    else: out += "."
  print(out)
    