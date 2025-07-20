n = int(input())
cows = list(map(int, input().split()))
cows.sort(reverse=True)

maxProfit = 0
tuition = 0
for i in range(n):
    if maxProfit <= cows[i] * (i + 1):
        maxProfit = cows[i] * (i + 1)
        tuition = cows[i]

print(maxProfit, tuition)