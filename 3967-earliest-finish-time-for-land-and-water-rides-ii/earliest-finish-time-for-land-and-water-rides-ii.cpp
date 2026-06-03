class Solution {
public:
    int earliestFinishTime(vector<int>& landS, vector<int>& landD, vector<int>& waterS, vector<int>& waterD) {
        int n = landS.size();
        int m = waterS.size();

        vector<pair<int,int>> v1 (n);
        vector<pair<int,int>> v2 (m);

        for(int i = 0; i<n; i++) {
            v1[i] = {landS[i],landD[i]};
        }

        for(int i = 0; i<m; i++) {
            v2[i] = {waterS[i],waterD[i]};
        }


        sort(v1.begin(),v1.end(), [] (const auto &p1, const auto &p2) {
            return p1.first + p1.second < p2.first + p2.second;
        });

        sort(v2.begin(),v2.end(), [] (const auto &p1, const auto &p2) {
            return p1.first + p1.second < p2.first + p2.second;
        });

        int ans = INT_MAX;

        for(int i = 0; i<m; i++) {
            if(v2[i].first >= v1[0].first + v1[0].second) {
                ans = min(ans,v2[i].first + v2[i].second);
            } else {
                ans = min(ans,v1[0].first + v1[0].second + v2[i].second);
            }
        }

        for(int i = 0; i<n; i++) {
            if(v1[i].first >= v2[0].first + v2[0].second) {
                ans = min(ans,v1[i].first + v1[i].second);
            } else {
                ans = min(ans,v2[0].first + v2[0].second + v1[i].second);
            }
        }

       return ans;
    }
};