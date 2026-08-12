class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int,int> freq;
        int l = 0, r = 0;
        int maxLen = 0;

        while(r < n) {
            freq[nums[r]]++;
            while(freq[nums[r]] > k) {
                freq[nums[l]]--;
                if(freq[nums[l]] == 0) freq.erase(nums[l]);
                l++;
            }

            maxLen = max(maxLen, r-l+1);
            r++;
        }

        return maxLen;
    }
};