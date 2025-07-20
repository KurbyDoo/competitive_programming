t = int(input())
for _ in range(t):
  n, k = map(int, input().split())
  gold = 0
  ans = 0
  for g in list(map(int, input().split())):
    if g >= k:
      gold += g
    
    elif g == 0 and gold > 0:
      gold -= 1
      ans += 1

  print(ans)