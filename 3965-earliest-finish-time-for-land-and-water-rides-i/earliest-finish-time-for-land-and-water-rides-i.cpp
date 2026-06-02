class Solution {
public:
    int earliestFinishTime(vector<int>& landS, vector<int>& landD, vector<int>& waterS, vector<int>& waterD) {
        int n = landS.size();
        int m = waterS.size();

        int ans = INT_MAX;

       for(int i = 0; i<n; i++) {
            int end = landS[i] + landD[i];
            for(int j = 0; j<m; j++) {
                if(waterS[j] >= end) {
                    ans = min(ans,waterS[j] + waterD[j]);
                } else {
                    ans = min(ans,end + waterD[j]);
                }
            }
       }

       for(int i = 0; i<m; i++) {
            int end = waterS[i] + waterD[i];
            for(int j = 0; j<n; j++) {
                if(landS[j] >= end) {
                    ans = min(ans,landS[j] + landD[j]);
                } else {
                    ans = min(ans,end + landD[j]);
                }
            }
       }

       return ans;
    }
};