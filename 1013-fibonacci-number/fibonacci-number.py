class Solution:
    def fib(self, n: int) -> int:
        if n == 0 or n == 1 : return n

        prev = 0
        cur = 1

        for i in range(2,n+1) :
            temp = prev + cur
            prev = cur
            cur = temp
        
        return temp