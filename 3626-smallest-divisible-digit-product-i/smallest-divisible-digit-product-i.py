class Solution:
    def smallestNumber(self, n: int, t: int) -> int:
        i = n
        while True :
            a = i
            prod = 1
            while a > 0 :
                prod *= a % 10
                a //= 10
            
            if prod % t == 0 :
                return i
            
            i += 1
        
        return -1