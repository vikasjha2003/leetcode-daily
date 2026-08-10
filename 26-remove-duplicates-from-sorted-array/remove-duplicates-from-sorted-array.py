class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        k = 1
        i = 1

        while i < len(nums) :
            if nums[k] > nums[k-1] :
                k += 1
                i += 1
                continue
            if nums[i] != nums[k-1] :
                nums[k] = nums[i]
                k += 1
            i += 1

        return k     
        