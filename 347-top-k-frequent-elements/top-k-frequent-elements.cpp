class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        sort(nums.begin(),nums.end());

        int count = 1;
        for(int i = 1; i<n; i++) {
            if(nums[i] == nums[i-1]) {
                count++;
            } else {
                pq.push({count,nums[i-1]});
                if(pq.size() > k) pq.pop();
                count = 1;
            } 
        }

        pq.push({count,nums[n-1]});
        if(pq.size() > k) pq.pop();

        vector<int> res;
        while(!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};