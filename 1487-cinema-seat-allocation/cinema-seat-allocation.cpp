class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,vector<int>> mpp;
        for(auto &it : reservedSeats) {
            mpp[it[0]].push_back(it[1]);
        }

        int resCnt = (n - mpp.size()) * 2;

        for(auto &it : mpp) {
            bool flag1 = true;
            bool flag2 = true;
            bool flag3 = true;

            for(int i : it.second) {
                if(i == 2 || i == 3) {
                    flag1 = false;
                } else if (i == 4 || i == 5) {
                    flag1 = false;
                    flag2 = false;
                } else if (i == 6 || i == 7) {
                    flag2 = false;
                    flag3 = false;
                } else if (i == 8 || i == 9) {
                    flag3 = false;
                }
            }

            if (flag1 && flag3) resCnt += 2;
            else if (flag1 || flag2 || flag3) resCnt++;
        }
        
        return resCnt;
    }
};