class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 1 or n == 2 : return n

        cur = 2
        prev = 1

        for i in range (3,n+1) :
            temp = cur + prev
            prev = cur
            cur = temp
        
        return temp