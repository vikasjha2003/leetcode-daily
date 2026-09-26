class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(),intervals.end());

        int start = intervals[0][0];
        int end = intervals[0][1];
        vector<vector<int>> res;

        for(int i = 1; i<n; i++) {
            if(intervals[i][0] > end) {
                res.push_back({start,end});
                start = intervals[i][0];
                end = intervals[i][1];
            } else {
                end = max(end,intervals[i][1]);
            }
        }

        res.push_back({start,end});

        return res;
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        return merge(intervals);
    }
};