class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        vector<vector<int>> res;
        int i = 0;
        int j = 0;
        while(i < series1.size() && j < series2.size()) {
            if(series1[i][0] == series2[j][0]) {
                res.push_back({series1[i][0] , series1[i][1] + series2[j][1]});
                i++;
                j++;
            } else if (series1[i][0] < series2[j][0]) {
                res.push_back({series1[i][0] , series1[i][1] + series2[j][1]});
                i++;
            } else {
                res.push_back({series2[j][0] , series1[i][1] + series2[j][1]});
                j++;
            }
        }

        while(i < series1.size()) {
            res.push_back(series1[i]);
            i++;
        }
        while(j < series2.size()) {
            res.push_back(series2[j]);
            j++;
        }
        
        return res;
    }
};