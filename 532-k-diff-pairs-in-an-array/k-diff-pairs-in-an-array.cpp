class Solution {
public:
    int findPairs(vector<int>& nums, int k) {

        unordered_map<int,int> freq;
        for(int i : nums) {
            freq[i]++;
        }

        int cnt = 0;
        for(auto &it : freq) {
            if(k == 0 && it.second >= 2) cnt++;
            if(k != 0 && freq.find(it.first-k) != freq.end()) cnt++; 
        }
        return cnt;
    }
};