from sys import stdout
from random import randint, shuffle
query_count = 0
# fake = set()
# while len(fake) < 10:
#     # fake.add(randint(1, 1000))
#     fake.add(len(fake) + 1 + 990)
n, m, q = map(int, input().split())

pairs = []
# n = 1000
# m = 10
# q = 950

def check_in_fake(a, b):
    global query_count
    print(f"? {a} {b}")
    query_count += 1
    stdout.flush()
    return int(input())
    # assert query_count <= q
    # assert 1 <= a <= n
    # assert 1 <= b <= n
    # return 0 if (a in fake) == (b in fake) else 1

def shrink(to_check: list):
    global possible
    next_check = []

    while len(to_check) > 0:
        if len(possible) >= 20: return -1
        if len(to_check) == 1:
            for i in to_check[-1]:
                possible.add(i)

            to_check.pop()
            break
            
        a, b = to_check[-1][0], to_check[-2][0]
        
        r = check_in_fake(a, b)

        if r == 1:
            for i in to_check[-1] + to_check[-2]:
                possible.add(i)

            pairs.append((to_check[-1], to_check[-2]))

        else:
            next_check.append(to_check[-1] + to_check[-2])

        to_check.pop()
        to_check.pop()

    return next_check

possible = set()
nums = [[i] for i in range(1, n + 1)]
shuffle(nums)

for _ in range(4):
    returned = shrink(nums)
    if returned == -1:
        break

    nums = returned.copy()
safe_num = -1
for i in range(1, n + 1):
    if i not in possible:
        safe_num = i
        break

possible = list(possible)
output = []
while pairs:
    a, b = pairs[-1]
    r = check_in_fake(a[0], safe_num)
    if r == 1:
        output.extend(a)
    else:
        output.extend(b)

    pairs.pop()


print("!", *output)
# print(query_count)

