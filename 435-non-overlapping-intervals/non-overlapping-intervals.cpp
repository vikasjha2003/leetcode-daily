class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),[](auto &v1, auto &v2) {
            return v1[1] < v2[1];
        });

        int prev = intervals[0][1];
        int cnt = 0;
        for(int i = 1; i < n; i++) {
            if(intervals[i][0] < prev) cnt++;
            else prev = intervals[i][1];
        }

        return cnt;
    }
};