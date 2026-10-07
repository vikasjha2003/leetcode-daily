class Solution {
public:
    int n;
    int minAddToMakeValid(string &s) {
        int res = 0;
        int cnt = 0;
        for(char c : s) {
            if(c == '(') cnt++;
            else if (c == ')') cnt--;

            if(cnt < 0) {
                res++;
                cnt++;
            }
        }

        return res + abs(cnt);
    }
    bool valid (string &s) {
        int cnt = 0;
        for(char c : s) {
            if(c == '(') cnt++;
            else if (c == ')') cnt--;

            if(cnt < 0) {
                return false;
            }
        }

        if(cnt > 0) return false;
        return true;
    }
    unordered_set<string> st;
    void removeParantheses(string &ans, string &s, int idx) {
        if(idx == s.length()) {
            if(ans.length() == n && valid(ans)) {
                st.insert(ans);
                return;
            }
            return;
        }

        if(s[idx] == '(' || s[idx] == ')') removeParantheses(ans,s,idx+1);

        ans.push_back(s[idx]);
        removeParantheses(ans,s,idx+1);
        ans.pop_back();        
    }
    vector<string> removeInvalidParentheses(string s) {
        n = s.length() - minAddToMakeValid(s);
        string ans = "";
        removeParantheses(ans,s,0);
        vector<string> result (st.begin(),st.end());
        return result;
    }
};