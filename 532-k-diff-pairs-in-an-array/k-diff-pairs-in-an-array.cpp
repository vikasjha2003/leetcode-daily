class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k == 0) {
            unordered_map<int,int> freq;
            for(int i : nums) {
                freq[i]++;
            }
            int cnt = 0;
            for(auto it : freq) {
                if(it.second >= 2) cnt++;
            }
            return cnt;
        }

        unordered_set<int> pr;
        int res = 0;
        for(int i : nums) {
            if(pr.find(i) != pr.end()) continue;
            if(pr.find(i + k) != pr.end()) res++;
            if(pr.find(i - k) != pr.end()) res++;
            pr.insert(i);
        }

        return res;
    }
};