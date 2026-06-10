class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(),intervals.end());
        vector<vector<int>> res;

        for(int i = 0; i<n; i++) {
            int st = intervals[i][0];
            int en = intervals[i][1];

            while(i < n && intervals[i][0] <= en) {
                en = max(en,intervals[i][1]);
                i++;
            }

            i--;
            res.push_back({st,en});
        }

        return res;
    }
};