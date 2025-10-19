t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    s = input()
    ans = 0
    zero_count = 0
    for i in range(n):
        if i < k - 1:
            zero_count += s[i] == "0"
            if ans == 0 and s[i] == "1":
                ans += 1
        else:
        
            if s[i] == "1" and zero_count == k - 1:
                ans += 1
            if s[i] == "0":
                zero_count += 1

            if s[i - k + 1] == "0":
                zero_count -= 1
    
    print(ans)
