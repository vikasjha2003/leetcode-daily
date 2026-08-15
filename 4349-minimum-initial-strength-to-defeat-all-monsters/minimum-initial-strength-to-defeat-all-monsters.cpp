class Solution {
public:
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        int n = monsters.size();

        vector<long long> da (n,0);
        for(int i = 0; i<boosts.size(); i++) {
            da[boosts[i][0]] += boosts[i][2];
            if(boosts[i][1] + 1 < n) da[boosts[i][1] +1] -= boosts[i][2];
        }

        int idx = -1;
        for(int i = 0; i<n; i++) {
            if(i > 0) da[i] += da[i-1];
            if(monsters[i] > da[i]) {
                idx = i;
            }
        }

        long long res = 0;

        for(int i = 0; i<=idx; i++) {
            if(i == idx) {
                res += monsters[i] - da[i];
            } else {
                res += monsters[i];
            }
        }

        return res;
    }
};