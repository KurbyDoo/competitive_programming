n, q = map(int, input().split())
s = input()

abc = s.count("ABC")
s = list(s)
for _ in range(q):
  a, b = input().split()
  a = int(a)

  if a >= 3 and s[a - 3] + s[a - 2] + s[a - 1] == "ABC":
    abc -= 1

  elif 2 <= a <= n - 1 and s[a - 2] + s[a - 1] + s[a] == "ABC":
    abc -= 1

  elif 1 <= a <= n - 2 and s[a - 1] + s[a] + s[a + 1] == "ABC":
    abc -= 1
  s[a - 1] = b
  if a >= 3 and s[a - 3] + s[a - 2] + s[a - 1] == "ABC":
    abc += 1

  elif 2 <= a <= n - 1 and s[a - 2] + s[a - 1] + s[a] == "ABC":
    abc += 1

  elif 1 <= a <= n - 2 and s[a - 1] + s[a] + s[a + 1] == "ABC":
    abc += 1

  print(abc)
