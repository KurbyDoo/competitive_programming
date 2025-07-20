import bisect
n, m, p = map(int, input().split())
meals = list(map(int, input().split()))
sides = list(map(int, input().split()))
meals.sort()
sides.sort()
sides_psa = [0] * (m + 1)
sides_psa[0] = sides[0]
for i in range(1, len(sides)):
    sides_psa[i] = sides_psa[i - 1] + sides[i]

total = 0
# print(meals, sides, sides_psa)
for meal in meals:
    left = bisect.bisect_right(sides, p - meal)
    # print(f"{left = }")
    # print(f"adding {sides_psa[left - 1]} + {meal} * {left}")
    # print(f"adding {p} * {m - left}")
    total += sides_psa[left - 1] + meal * left
    total += p * (m - left)

print(total)
