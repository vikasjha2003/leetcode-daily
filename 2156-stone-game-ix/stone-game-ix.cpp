class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int freq[3] = {0,0,0};

        for(int i : stones) {
            freq[i%3]++;
        }

        if(freq[0] % 2 == 0) return freq[1] > 0 && freq[2] > 0;
        return abs(freq[1] - freq[2]) > 2;
    }
};