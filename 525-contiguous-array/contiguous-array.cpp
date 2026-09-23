class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> seen;
        int res = 0;
        int len = 0;
        for(int i = 0; i<n; i++) {
            if(nums[i] == 0) len++;
            else len--;
            if(len == 0) res = i+1;
            if(seen.find(len) != seen.end()) {
                res = max(res,i-seen[len]);
            } else {
                seen[len] = i;
            }
        }
        return res;
    }
};