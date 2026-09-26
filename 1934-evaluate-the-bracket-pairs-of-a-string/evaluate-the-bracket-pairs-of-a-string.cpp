class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.length();

        unordered_map<string,string> kv;
        for(auto &it : knowledge) {
            kv[it[0]] = it[1];
        }

        string res = "";
        for(int i = 0; i<n; i++) {
            if(s[i] == '(') {
                i++;
                string key = "";

                while(s[i] != ')') {
                    key += s[i];
                    i++;
                }

                if(kv.find(key) == kv.end()) {
                    res.push_back('?');
                } else {
                    res += kv[key];
                }
            } else {
                res.push_back(s[i]);
            }
        }

        return res;
    }
};