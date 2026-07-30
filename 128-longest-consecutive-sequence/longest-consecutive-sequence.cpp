class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;

        sort(nums.begin(), nums.end());
        int maxlen = 1;
        int curlen = 1;

        for(int i = 1; i<n; i++) {
            if(nums[i] == nums[i-1]) continue;
            else if (nums[i] == nums[i-1] + 1) curlen++;
            else curlen = 1;
            maxlen = max(maxlen, curlen);
        }

        return maxlen;
    }
};