class Solution {
public:
    // Brute force
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size();

        priority_queue<pair<int,int>> pq;
        for(int i = 0; i<n; i++) {
            pq.push({nums[i],i});
        }

        int res = 0;
        for(int i = 0; i<n-k; i++) {
            while(pq.top().second < i || pq.top().second - i < k) {
                pq.pop();
            }
            res = max(nums[i] + pq.top().first , res);
        }

        return res;
    }
};