class Solution:
    def maxProduct(self, n: int) -> int:
        maxi = 0
        smaxi = 0

        while n > 0 :
            a = n % 10
            if maxi < a :
                smaxi = maxi
                maxi = a
            elif smaxi < a :
                smaxi = a
            n //= 10
        
        return maxi * smaxi
        