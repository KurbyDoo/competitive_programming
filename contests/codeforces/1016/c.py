import math
sieve = [True] * 35000
sieve[0] = False
sieve[1] = False
primes = []
for i in range(2, 35000):
    if not sieve[i]: continue
    primes.append(i)
    for j in range(i * 2, 35000, i):
        sieve[j] = False

def isprime(x):
    if x == 1: return False
    for d in primes:
        if d >= x: return True
        if x % d == 0: return False
    return True

t = int(input())
for _ in range(t):
    x, k = map(int, input().split())
    if x == 1:
        print("YES" if isprime(int("1" * k)) else "NO")
    elif k > 1:
        print("NO")
    
    else:
        print("YES" if isprime(x) else "NO")