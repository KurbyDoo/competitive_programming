size = int(input())
num = list(input())
for i in range(size - 1):
    if (int(num[i]) < int(num[i + 1])):
        num[i], num[i + 1] = num[i + 1], num[i]
        break
print("".join(num))