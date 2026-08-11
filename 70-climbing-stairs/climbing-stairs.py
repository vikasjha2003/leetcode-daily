class Solution:
    def climb(self, n: int, dp : list[int]) -> int :
        if n == 1 or n == 2 : return n
        if dp[n] != -1 : return dp[n]
        dp[n] = self.climb(n-1,dp) + self.climb(n-2,dp)
        return dp[n]

    def climbStairs(self, n: int) -> int:
        dp = [-1] * (n+1)
        return self.climb(n,dp)