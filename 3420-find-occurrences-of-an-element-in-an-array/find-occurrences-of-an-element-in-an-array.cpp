class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        int n = nums.size();

        vector<int> pos;
        for(int i = 0; i<n; i++) {
            if(nums[i] == x) pos.push_back(i);
        }

        vector<int> res;
        for(int q : queries) {
            if(q > pos.size()) res.push_back(-1);
            else res.push_back(pos[q-1]);
        }

        return res;
    }
};