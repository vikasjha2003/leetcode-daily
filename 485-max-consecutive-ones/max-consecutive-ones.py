class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        maxCnt = 0
        cnt = 0

        for i in range(0,len(nums)) :
            if nums[i] == 1 :
                cnt += 1
            else :
                maxCnt = max(cnt,maxCnt)
                cnt = 0
        
        return max(cnt, maxCnt)