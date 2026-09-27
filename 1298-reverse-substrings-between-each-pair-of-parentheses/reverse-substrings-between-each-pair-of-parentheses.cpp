class Solution {
public:
    void reverse(string &s , int l , int r) {
        while(l < r) {
            swap(s[l],s[r]);
            l++;
            r--;
        }
    }
    string reverseParentheses(string s) {
        int n = s.length();
        stack<pair<char,int>> st;
        for(int i = 0; i<n; i++) {
            if(s[i] == '(') st.push({'(',i});
            if(s[i] == ')') {
                auto it = st.top();
                st.pop();
                reverse(s,it.second,i);
            }
        }

        string res = "";

        for(int i = 0; i<n; i++) {
            if(s[i] == '(' || s[i] == ')') continue;
            res.push_back(s[i]);
        }

        return res;
    }
};