playlist = list("ABCDE")

while True:
    b, n = int(input()), int(input())
    if b == 4:
        break

    for _ in range(n):
        if b == 1:
            playlist.append(playlist.pop(0))

        if b == 2:
            playlist.insert(0, playlist.pop())

        if b == 3:
            playlist.insert(0, playlist.pop(1))

print(" ".join(playlist))