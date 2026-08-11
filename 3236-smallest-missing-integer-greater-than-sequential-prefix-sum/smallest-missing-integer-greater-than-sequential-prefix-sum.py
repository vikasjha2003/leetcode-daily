class Solution:
    def missingInteger(self, nums: List[int]) -> int:
        n = len(nums)
        st = set()
        sum = nums[0]
        flag = True
        st.add(nums[0])
        for i in range (1,n) :
            if nums[i] == nums[i-1] + 1 and flag == True :
                sum += nums[i]
            elif flag == True :
                flag = False
            
            st.add(nums[i])

        while True :
            if sum not in st :
                return sum
            else : 
                sum += 1

        return -1