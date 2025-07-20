import random

with open('DMOJ/graphtheory/test.txt', 'w') as f:
    n = 10000
    m = 20000
    q = 1000

    f.write(f"{n} {m} {q}\n")
    for _ in range(m):
        a = random.randint(1, n)
        b = random.randint(1, n)
        while a == b:
            b = random.randint(1, n)

        f.write(f"{a} {b}\n")

    for _ in range(q):
        a = random.randint(1, n)
        b = random.randint(1, n)
        while a == b:
            b = random.randint(1, n)

        f.write(f"{a} {b}\n")

