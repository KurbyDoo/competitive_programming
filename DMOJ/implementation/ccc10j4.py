nums = list(map(int, input().split()))
while nums != [0]:
    n = nums.pop(0)
    m = 99999
    # best = []
    diff = []
    for i in range(n - 1):
        diff.append(nums[i + 1] - nums[i])

    for i in range(1, n):
        test = []
        for j in range(i):
            test.append(diff[j])

        works = True
        for j in range(0, n, i):
            for k in range(i):
                # print(test[k], diff[j + k])
                if j + k >= n - 1:
                    break
                if test[k] != diff[j + k]:
                    works = False

        # print(test)
        if works:
            m = min(i, m)

    print(m if m != 99999 else 0)
    # for i in range(m):
    #     print(abs(diff[i]))
    nums = list(map(int, input().split()))