class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size();
        
        vector<int> freq (61,0);
        int cnt = 0;

        for(int i : time) {
            int val = i % 60;
            cnt += freq[60 - val];
            if(val == 0) freq[60]++;
            else freq[val]++;
        }

        return cnt;
    }
};