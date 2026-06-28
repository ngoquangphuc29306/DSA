class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [float('inf')] * (amount + 1)
        dp[amount] = 0

        for cur in reversed(range(amount)):
            for coin in coins:
                if cur + coin <= amount:
                    dp[cur] = min(dp[cur], 1 + dp[cur + coin])

        return -1 if dp[0] == float('inf') else dp[0]
