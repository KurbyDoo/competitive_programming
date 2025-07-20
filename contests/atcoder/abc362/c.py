n = int(input())
l = []
r = []
for i in range(n):
    a, b = map(int, input().split())
    l.append(a)
    r.append(b)

output = []
cur_sum = 0
for i in range(n):
    if l[i] > 0:
        output.append(l[i])
    elif r[i] < 0:
        output.append(r[i])

    else:
        output.append(0)
    cur_sum += output[-1]

for i in range(n):
    # print(f"{cur_sum = } {l[i]} {output[i]} {r[i]}")
    if cur_sum > 0:
        if output[i] - l[i] > cur_sum:
            output[i] -= cur_sum
            cur_sum = 0

        elif output[i] - l[i] > 0:
            cur_sum -= output[i] - l[i]
            output[i] = l[i]

    elif cur_sum < 0:
        if output[i] - r[i] < cur_sum:
            output[i] -= cur_sum
            cur_sum = 0

        elif output[i] - r[i] < 0:
            cur_sum -= output[i] - r[i]
            output[i] = r[i]

if cur_sum == 0:
    print("Yes")
    print(*output)
else:
    print("No")