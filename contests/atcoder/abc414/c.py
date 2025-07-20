# annoying implementation
# https://atcoder.jp/contests/abc414/tasks/abc414_c
A = int(input())
N = int(input())
ans = 0
max_num = f"{A - 1}"
while int(max_num, A) < N:
    max_num += f"{A - 1}"
max_length = len(str(N)) // 2

if N < 10:
    ans += N * (N + 1) // 2

for i in range(1, 10 ** (max_length // 2)):
    for c in range(0, 10):
        num = int(str(i) + str(i)[::-1])
        if num > N:
            break
        base = str(int(str(num), A, ))
        if base == reversed(base):
            ans += num
        num = int(str(i) + str(c) + str(i)[::-1])
        base = str(int(str(num), A))
        if base == reversed(base):
            ans += num

print(ans)
