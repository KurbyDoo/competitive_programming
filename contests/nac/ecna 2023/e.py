import sys
sequence = input()
n = len(sequence)
possible = [[] for _ in range(n)]
if "OO" in sequence or sequence[-1] != "O":
    print("INVALID")
    sys.exit()

for i in range(3, 1000):
    if ((1 << i) - 1) % 3 == 0:
        possible[0].append(((1 << i) - 1) // 3)

for idx in range(0, n - 1):
    c = sequence[-idx - 2]
    for item in possible[idx]:
        if c == "E":
            possible[idx + 1].append(item * 2)
        else:
            if (item - 1) % 3 == 0:
                possible[idx + 1].append((item - 1)//3)

# print(possible)
if len(possible[-1]) == 0:
    print("INVALID")
else:
    print(min(possible[-1]))