from collections import defaultdict


def approach1(n: int, k: int, cows: str):
    grass = list(cows)
    cows_patches = defaultdict(int)
    patches_cows = defaultdict(list)
    for i in range(n):
        for j in range(max(0, i - k), min(n, i + k + 1)):
            if grass[j] == cows[i]:
                cows_patches[i] += 1
                patches_cows[j].append(i)

    count = 0
    for i in range(n):
        can_remove = True
        for c in patches_cows[i]:
            if cows_patches[c] - 1 == 0:
                can_remove = False
                break

        if can_remove:
            for c in patches_cows[i]:
                cows_patches[c] -= 1

            grass[i] = '.'
            count += 1

    print(n - count)
    print("".join(grass))


def minimum_patches(n: int, k: int, cows: str):
    grass = ["." for _ in range(n)]
    cows_patches = [0 for _ in range(n)]
    count = 0

    for _ in range(n):
        max_patch_index = None
        max_n = 0
        max_type = ""
        for i in range(n):
            if grass[i] != ".":
                continue
            g_count = 0
            h_count = 0
            for j in range(max(0, i - k), min(n, i + k + 1)):
                if cows_patches[j] == 0 and cows[j] == "G":
                    # print(f"{cows[j] = } is not fed")
                    g_count += 1

                elif cows_patches[j] == 0 and cows[j] == "H":
                    # print(f"{cows[j] = } is not fed")
                    h_count += 1

            if g_count > max_n:
                max_n = g_count
                max_type = "G"
                max_patch_index = i
                # print(f"{max_patch_index = } {max_n = }")

            elif h_count > max_n:
                max_n = h_count
                max_patch_index = i
                max_type = "H"
                # print(f"{max_patch_index = } {max_n = }")

        # print(cows_patches, grass, f"{max_patch_index = } {max_type = }")
        if max_patch_index == None:
            break

        grass[max_patch_index] = max_type
        count += 1
        for j in range(max(0, max_patch_index - k), min(n, max_patch_index + k + 1)):
            if cows[j] == max_type:
                cows_patches[j] += 1

    print(count)
    print("".join(grass))


t = int(input())

for _ in range(t):
    n, k = map(int, input().split())
    minimum_patches(n, k, input())
