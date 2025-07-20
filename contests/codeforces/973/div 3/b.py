t = int(input())
for _ in range(t):
  na, k = map(int, input().split())
  if na % 2 == 0:
    n = na // 2
  else:
    n = na // 2 + 1

  if (na - k) % 2 == 0:
    k = (na - k) // 2

  else:
    k = (na - k) // 2 + 1
  print("YES" if (n - k) % 2 == 0 else "NO")