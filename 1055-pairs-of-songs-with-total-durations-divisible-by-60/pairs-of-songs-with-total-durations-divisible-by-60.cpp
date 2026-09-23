class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size();
        
        unordered_map<int,int> freq;
        int cnt = 0;

        for(int i : time) {
            int val = i % 60;
            if(freq.find(60 - val) != freq.end()) cnt += freq[60 - val];
            if(val == 0) freq[60]++;
            else freq[val]++;
        }

        return cnt;
    }
};