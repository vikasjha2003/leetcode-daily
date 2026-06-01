class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());

        int ans = 0;
        int skip = 0;
        for(int i = cost.size() - 1; i >= 0; i--) {
            ans += cost[i];
            skip++;
            if(skip == 2) {
                i--;
                skip = 0;
            }
        }

        return ans;
    }
};