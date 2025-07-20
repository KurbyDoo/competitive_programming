n = int(input())
people = list(map(int, input().split()))
total = sum(people)
length = (1 << n).bit_length()
ans = total
for mask in range(1 << n):
    s = 0
    for i in range(length):
        if (mask >> i) & 1:
            s += people[i]

    if abs(s - (total - s)) <= abs(ans - (total - ans)):
        ans = s
print(max(ans, total - ans))
