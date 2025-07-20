t = int(input())
for _ in range(t):
  n = int(input())
  wealth = sorted(map(int, input().split()))

  if n <= 2:
    print(-1)
    continue

  mid = n // 2
  average = sum(wealth) / n
  mid_income = wealth[mid]
  if (sum(wealth) > mid_income * n * 2):
    print(0)
    continue
  x = mid_income * n * 2  - sum(wealth) + 1
  print(x)