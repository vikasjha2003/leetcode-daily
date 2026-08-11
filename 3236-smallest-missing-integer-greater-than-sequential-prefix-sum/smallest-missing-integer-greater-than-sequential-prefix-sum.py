class Solution:
    def missingInteger(self, nums: List[int]) -> int:
        sum = nums[0]
        for i in range (1,len(nums)) :
            if nums[i] == nums[i-1] + 1 :
                sum += nums[i]
            else :
                break

        nums.sort()
        while True :
            low = 0
            high = len(nums) -1
            flag = False
            while low <= high :
                mid = low + (high - low) // 2

                if nums[mid] == sum :
                    flag = True
                    break
                elif nums[mid] < sum :
                    low = mid + 1
                else :
                    high = mid - 1
            
            if not flag : return sum
            else : sum += 1

        return -1
