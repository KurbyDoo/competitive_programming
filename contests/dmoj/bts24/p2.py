n, m = map(int, input().split())
points = list(map(int, input().split()))
students = list(map(int, input().split()))

da = [0] * (m * 2 + 1)
front = 0
for i in range(n):
  da[front] += points[i]
  da[front + students[i]] -= points[i]
  front = (front + students[i]) % m
  # print(*da)

for i in range(m * 2):
  da[i + 1] += da[i]

# print(*da)
out = []
for i in range(m):
  out.append(da[i] + da[i + m])
print(*out)