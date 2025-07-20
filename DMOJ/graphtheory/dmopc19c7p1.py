a, b, c, d = map(int, input().split())
n_carbon = a + b + c + 1
h_required = n_carbon * 4 - 2 * a - 4 * b - 6 * c
if d != h_required:
    print("invalid")
else:
    print(f"C{n_carbon}H{h_required}")

s = list("ASDASDSAD")
A = [0] * (len(s) * 2 + 1)
print(A)