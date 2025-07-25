class Solution:
    def climbStairs(self, n: int) -> int:
        dp = [0 for _ in range(n + 1)]
        dp[0] = 1
        for i in range(n):
            if i + 1 <= n:
                dp[i + 1] += dp[i]

            if i + 2 <= n:
                dp[i + 2] += dp[i]

        print(dp)
        return dp[-1]
