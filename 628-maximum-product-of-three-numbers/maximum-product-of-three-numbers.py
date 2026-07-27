class Solution:
    def maximumProduct(self, nums: List[int]) -> int:
        n = len(nums)

        list.sort(nums)

        res = nums[n-1] * nums[n-2] * nums[n-3]

        if nums[n-1] * nums[0] * nums[1] > res :
            res = nums[n-1] * nums[0] * nums[1]
        elif nums[0] * nums[1] * nums[2] > res :
            res = nums[0] * nums[1] * nums[2]
        
        return res
            
        

        
        