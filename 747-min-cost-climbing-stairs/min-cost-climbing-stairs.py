class Solution:
    def solve(self, cost: List[int], idx : int, dp: List[int]) -> int:
        if idx >= len(cost) :
            return 0
        if dp[idx] != -1 : return dp[idx]
        
        dp[idx] = cost[idx] + min(self.solve(cost,idx+1,dp),self.solve(cost,idx+2,dp))

        return dp[idx]

    def minCostClimbingStairs(self, cost: List[int]) -> int:
        dp = [-1] * len(cost)
        return min(self.solve(cost,0,dp),self.solve(cost,1,dp))