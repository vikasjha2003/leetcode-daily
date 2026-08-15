class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();

        int res = 0;
        for(int i : nums) {
            res ^= i;
        }
        if(res != 0) return n;

        for(int i : nums) {
            if(res ^ i != 0) return n-1;
        }
        
        return 0;
    }
};