m = int(input())
best = float('inf')

slots = [input() * 3 for _ in range(3)]
print(*slots)
orders = [(0, 1, 2), (0, 2, 1), (1, 0, 2), (1, 2, 0), (2, 0, 1), (2, 1, 0)]
for target in "0123456789":
    for first, second, third in orders:
        cur_time = 0
        # print(f"trying {target} {first} {second} {third}")
        if target not in slots[first][cur_time:]:
            # print(f"{target} not in {first}")
            continue

        distance = slots[first][cur_time:].index(target) + 1
        cur_time += distance

        if target not in slots[second][cur_time:]:
            continue

        distance = slots[second][cur_time:].index(target) + 1
        cur_time += distance

        if target not in slots[third][cur_time:]:
            continue

        distance = slots[third][cur_time:].index(target) + 1
        cur_time += distance

        # print(f"target: {target}, cur_time: {cur_time}")
        best = min(best, cur_time)
print(best - 1 if best != float('inf') else -1)
