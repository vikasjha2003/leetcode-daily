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
        set<pair<int,int>> pair;
        int res = 0;
        for(int i : nums) {
            if(pr.find(i + k) != pr.end()) {
                pair.insert({i,i+k});
                pair.insert({i+k,i});
            }
            if(pr.find(i - k) != pr.end()) {
                pair.insert({i,i-k});
                pair.insert({i-k,i});
            }
            pr.insert(i);
        }

        return pair.size() / 2;
    }
};