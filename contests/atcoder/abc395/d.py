n, q = map(int, input().split())

loc = [i for i in range(n + 1)]
id_label = [i for i in range(n + 1)]
label_id = [i for i in range(n + 1)]
for _ in range(q):
    t, a, *b = map(int, input().split())
    if t == 1:
        b = b[0]
        loc[a] = label_id[b]
    elif t == 2:
        b = b[0]
        loc1, loc2 = label_id[a], label_id[b]
        label_id[a], label_id[b], id_label[loc1], id_label[loc2] = label_id[b], label_id[a], id_label[loc2], id_label[loc1]

    else:
        print(id_label[loc[a]])

    # print(loc, id_label, label_id)

