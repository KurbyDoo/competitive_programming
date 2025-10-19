n = int(input())
jumps = sorted(list(map(int, input().split())))
small = jumps[0]//3
large = jumps[-1]//3
mid = jumps[1] - small - small
print(small, mid, large)