class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();

        unordered_map<string,vector<string>> mpp;
        for(string &s : strs) {
            string str = s;
            sort(str.begin(),str.end());
            mpp[str].push_back(s);
        }

        vector<vector<string>> res;
        for(auto &it : mpp) {
            res.push_back(it.second);
        }

        return res;
                
    }
};