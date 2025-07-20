class Solution:
    def coinChange(self, coins: list[int], amount: int) -> int:
        # Create an array the length of our target + 1
        # Each index stores the min number of coins to reach that value
        m = [amount + 1 for _ in range(amount + 1)]

        # Amount of 0 needs 0 coins
        m[0] = 0

        # For every number between 0 and our target
        for i in range(amount):
            for c in coins:

                # If the current number + coin is <= target
                if i + c <= amount:
                    # Set the number of coins needed to reach i + coin value to
                    # the number needed for the previous amount + 1
                    # If it is smaller that previous amount
                    m[i + c] = min(m[i + c], m[i] + 1)

        # If last value (Target amount) is never reached
        if m[-1] == amount + 1:
            return -1

        # Return
        return m[-1]
