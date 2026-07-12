class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();

        if(n == 0) return arr;

        vector<int> res (arr.begin(),arr.end());
        sort(res.begin(),res.end());

        int cnt = 1;
        unordered_map<int,int> mpp;

        mpp[res[0]] = cnt++;

        for(int i = 1; i<n; i++) {
            if(res[i-1] != res[i]) mpp[res[i]] = cnt++;
        }

        for(int i = 0; i<n; i++) {
            res[i] = mpp[arr[i]];
        }

        return res;
    }
};