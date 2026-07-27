class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        maxi = 0
        smaxi = 0

        for num in nums :
            if maxi < num :
                smaxi = maxi
                maxi = num
            elif smaxi < num :
                smaxi = num
        
        return (maxi - 1) * (smaxi -1)