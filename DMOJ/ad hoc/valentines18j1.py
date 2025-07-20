import sys
input = sys.stdin.readline
n = int(input())
output = "Cuteness by definition is similarity to Carol"
big = 0
for _ in range(n):
    a = int(input())
    big = max(a, big)
    if big > 1000:
        output = "Cuteness by definition is similarity to Cactus"
    
    if big > 10000:
        output = "Something is wrong with these cuteness values"
print(output)
