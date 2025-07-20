n = int(input())

order = {"I": 1, "V": 5, "X": 10, "L": 50, "C": 100, "D": 500, "M": 1000}
special = {"IV": 4, "IX": 9, "XL": 40, "XC": 90, "CD": 400, "CM": 900}
numbers = {1: "I", 4: "IV", 5: "V", 9: "IX", 10: "X", 40: "XL", 50: "L", 90: "XC", 100: "C", 400: "CD", 500: "D", 900: "CM", 1000: "M"}

def convert(num: str) -> int:
    value = 0
    for s in special.keys():
        # print(s)
        if s in num:
            # print("special")
            i = num.index(s)
            value += special[s]
            # print(num)
            num = num[:i] + num[i + 2:]
            # print(num)

    for s in order.keys():
        if s in num:
            c = num.count(s)

            value += order[s] * c

    return value

def create(number: int) -> str:
    # print(f"creating {number}")
    if number > 1000:
        return "CONCORDIA CUM VERITATE"
    placeValue = len(list(str(number))) - 1
    string = ""
    for n in list(map(int, str(number))):
        if n == 9 or n == 4:
            string += numbers[n * (10**placeValue)]

        elif n >= 5:
            string += (numbers[5 * 10**placeValue])
            string += (numbers[10**placeValue]*(n-5))

        elif n > 0:
            string += (numbers[10**placeValue]*n)

        placeValue -= 1

    return string

for _ in range(n):
    n1, n2 = input()[:-1].split("+")

    v1 = convert(n1)
    v2 = convert(n2)
    # print(f"{v1 = }, {v2 = }")
    print(f"{n1}+{n2}={create(v1 + v2)}")

# 7
# XCIX+I=
# VII+II=
# XXIX+X=
# M+I=
# CMXCIX+I=
# DC+XXIII=
# DCCLXXXVIII+CLXV=