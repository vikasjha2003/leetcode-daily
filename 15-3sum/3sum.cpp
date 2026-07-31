class Solution {
public:

    // -4,-1,-1,0,1,2

    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        vector<vector<int>> res;

        for(int i = 0; i< n-2; i++) {
            if(i > 0 && nums[i] == nums[i -1]) continue;
            int left = i + 1;
            int right = n - 1;
            while(left < right) {
                if(nums[left] + nums[right] + nums[i] == 0) {
                    res.push_back({nums[i], nums[left], nums[right]});
                    while(left < right && nums[left] == nums[left + 1]) left++;
                    while(left < right && nums[right] == nums[right-1]) right--;
                    left++;
                    right--;
                } else if (nums[left] + nums[right] + nums[i] < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        return res;
    }
};