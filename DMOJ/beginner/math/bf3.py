import math
import sys

n = int(input())

def primeCheck(num):
    for div in range(7, int(math.sqrt(num) + 0.5), 2):
        if num % div == 0:
            return True

    return False
if n == 1 or n == 2:
    print(2)

elif n == 3 or n == 4:
    print(5)

elif n == 5 or n == 6:
    print(7)

else:
    if n%2 == 0:
        n += 1

    for num in range(n, n*2, 2):
        # print(f"checking {num}")
        if num % 3 == 0:
            continue

        if num % 5 == 0:
            continue
    
        if primeCheck(num):
            continue

        print(num)
        break
    