class Solution {
public:
    int earliestFinishTime(vector<int>& landS, vector<int>& landD, vector<int>& waterS, vector<int>& waterD) {
        int n = landS.size();
        int m = waterS.size();

        int land = INT_MAX;
        int water = INT_MAX; 

        for(int i = 0; i < n; i++) {
            land = min(land,landS[i] + landD[i]);
        }

        for(int i = 0; i < m; i++) {
            water = min(water,waterS[i] + waterD[i]);
        }

        int ans = INT_MAX;

        for(int i = 0; i < n; i++) {
            if(landS[i] >= water) {
                ans = min(ans,landS[i] + landD[i]);
            } else {
                ans = min(ans,water + landD[i]);
            }
        
        }

        for(int i = 0; i < m; i++) {
            if(waterS[i] >= land) {
                ans = min(ans,waterS[i] + waterD[i]);
            } else {
                ans = min(ans,land + waterD[i]);
            }  
        }

       return ans;
    }
};