from collections import defaultdict

costs = defaultdict(int)
with open("contests\codingquest\p1\input.txt") as f:
    lines = f.readlines()
    for line in lines:
        name, t, v = line.strip().split()
        print(f"processing {name} {t} {v}")
        if t in ["Seat", "Meals", "Luggage", "Fee", "Tax"]:
            costs[name] += int(v)

        else:
            costs[name] -= int(v)

    print(costs.values())
    print(min(costs.values()))
