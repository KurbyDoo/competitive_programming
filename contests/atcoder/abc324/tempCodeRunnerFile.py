n = int(input())
nums = list(map(int, input().split()))
out = "Yes"
past = -1
for n in nums:
    if n == past or past == -1:
        past = n
    else:
        out = "No"
        break
print(out)