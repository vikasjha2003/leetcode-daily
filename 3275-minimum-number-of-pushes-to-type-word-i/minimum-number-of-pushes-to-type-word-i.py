class Solution:
    def minimumPushes(self, word: str) -> int:
        res = 0
        n = len(word)
        i = 0

        while i < n :
            if i < 8 :
                res += 1
            elif i < 16 :
                res += 2
            elif i < 24 :
                res += 3
            else :
                res += 4
            
            i += 1
        
        return res
            