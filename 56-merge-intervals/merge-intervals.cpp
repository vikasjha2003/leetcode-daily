class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(),intervals.end());
        vector<vector<int>> res;

        int st = intervals[0][0];
        int en = intervals[0][1];

        for(int i = 1; i<n; i++) {
            if(intervals[i][0] <= en) {
                en = max(en,intervals[i][1]);
            } else {
                res.push_back({st,en});
                st = intervals[i][0];
                en = intervals[i][1];
            }
        }

        res.push_back({st,en});

        return res;
    }
};