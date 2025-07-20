n = int(input())

output = ""
for i in range(n + 1):
    for j in range(1, 10):
        if n % j != 0: continue
        if i % (n // j) == 0:
            output += str(j)
            break
    
    if len(output) != i + 1:
        output += '-'

print(output)