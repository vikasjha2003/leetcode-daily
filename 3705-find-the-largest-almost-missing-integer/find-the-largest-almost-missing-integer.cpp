class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        if(k == n) return *max_element(nums.begin(),nums.end());

        unordered_map<int,int> freq;
        for(int it : nums) {
            freq[it]++;
        }
        
        int res = -1;
        if(k == 1) {
            for(auto it : freq) {
                if(it.second == 1) {
                    res = max(res,it.first);
                }
            }
        } else {
            if (freq[nums[0]] == 1) {
                res = max(res,nums[0]);
            }
            if (freq[nums.back()] == 1) {
                res = max(res,nums.back());
            }
        }

        return res;        
    }
};