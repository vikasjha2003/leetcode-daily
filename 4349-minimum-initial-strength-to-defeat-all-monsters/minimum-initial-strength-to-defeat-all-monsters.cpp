class Solution {
public:
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        int n = monsters.size();

        vector<long long> da (n,0);
        for(auto &b : boosts) {
            da[b[0]] += b[2];
            if(b[1] + 1 < n) da[b[1] +1] -= b[2];
        }

        long long res = 0;
        long long sum = 0;
        long long bonus = 0;
        for(int i = 0; i<n; i++) {
            bonus += da[i];
            sum += monsters[i];
            if(monsters[i] > bonus) {
                res = sum - bonus;
            }
        }

        return res;
    }
};