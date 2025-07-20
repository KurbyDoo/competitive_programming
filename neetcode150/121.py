class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        profit = 0

        l = 0
        for r in range(1, len(prices)):
            if prices[r] < prices[l]:
                l = r

            profit = max(profit, prices[r] - prices[l])

        return profit
