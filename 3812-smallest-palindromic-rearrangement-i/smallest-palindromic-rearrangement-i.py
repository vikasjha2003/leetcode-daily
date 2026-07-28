class Solution:
    def smallestPalindrome(self, s: str) -> str:
        n = len(s)
        arr = [0] * 26

        for c in s :
            arr[ord(c) - ord('a')] += 1

        idx = -1
        st = ""

        for i in range (26) :
            if arr[i] % 2 == 1 : idx = i
            st += chr(i + 97) * (arr[i] // 2)
        
        temp = st

        if idx != -1 : st += chr(idx + 97)

        st += temp[::-1]
        
        return st        