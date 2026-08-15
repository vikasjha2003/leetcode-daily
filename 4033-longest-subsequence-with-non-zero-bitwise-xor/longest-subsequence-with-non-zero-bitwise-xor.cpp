class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();

        int res = 0;
        bool zeroFlag = true;
        for(int i : nums) {
            res ^= i;
            if(i != 0) {
                zeroFlag = false;
            }
        }

        if(zeroFlag) return 0;
        
        return res == 0 ? n-1 : n;
    }
};