class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end(),[](auto &v1 , auto &v2) {
            return v1[1] < v2[1];
        });

        int prev = points[0][1];
        int cnt = 1;
        for(int i = 1; i<n; i++) {
            if(points[i][0] > prev) {
                cnt++;
                prev = points[i][1];
            }
        }

        return cnt;
    }
};