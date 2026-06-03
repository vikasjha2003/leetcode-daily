class Solution {
public:
    int earliestFinishTime(vector<int>& landS, vector<int>& landD, vector<int>& waterS, vector<int>& waterD) {
        int n = landS.size();
        int m = waterS.size();

        int land = INT_MAX;
        int water = INT_MAX; 

        for(int i = 0; i < max(n,m); i++) {
            if(i < n) land = min(land,landS[i] + landD[i]);
            if(i < m) water = min(water,waterS[i] + waterD[i]);
        }

        int ans = INT_MAX;

        for(int i = 0; i < max(m,n); i++) {
            if(i < m) {
                if(waterS[i] >= land) {
                    ans = min(ans,waterS[i] + waterD[i]);
                } else {
                    ans = min(ans,land + waterD[i]);
                }   
            }

            if(i < n) {
                if(landS[i] >= water) {
                    ans = min(ans,landS[i] + landD[i]);
                } else {
                    ans = min(ans,water + landD[i]);
                }
            }
        }

       return ans;
    }
};