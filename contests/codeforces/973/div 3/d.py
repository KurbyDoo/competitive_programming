t = int(input())
for _ in range(t):
  n, d, k = map(int, input().split())
  starts = []
  ends = []
  for i in range(k):
    l, r = map(int, input().split())
    starts.append((l, 1))
    ends.append((r + 1, -1))
  
  big = (1, -1)
  small = (1, 100010)
  count = 0

  starts.sort()
  ends.sort()

  starts.reverse()
  ends.reverse()
  for i in range(d, n + 1):
    while starts and starts[-1][0] <= i:
      count += 1
      starts.pop()

    while ends and ends[-1][0] <= i - d + 1:
      count -= 1
      ends.pop()

    if big[1] < count:
      big = (i - d + 1, count)

    if small[1] > count:
      small = (i - d + 1, count)

  print(big[0], small[0])