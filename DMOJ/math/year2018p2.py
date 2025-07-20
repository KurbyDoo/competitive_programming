is_prime = [True] * 100010
is_prime[1] = False
for i in range(2, 100005):
    if is_prime[i]:
        for j in range(i + i, 100005, i):
            is_prime[j] = False

int(input())
ans = 0
for n in list(map(int, input().split())):
    ans += is_prime[n]
print(ans)