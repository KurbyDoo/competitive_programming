q = int(input())
queue = [0]
offset = 0
sidx = 1
for i in range(q):
    ii = input().split()
    a = int(ii[0])
    if a == 1:
        b = int(ii[1])
        queue.append(b + queue[-1])

    elif a == 2:
        offset += (queue[sidx] - queue[sidx - 1])
        sidx += 1

    elif a == 3:
        b = int(ii[1]) - 1
        print(queue[sidx + b - 1] - offset)

    # print(*queue)