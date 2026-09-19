class Solution {
public:
    int n, m;

    bool solve(string &s, string &p, int i , int j) {
        if(i == n && j == m) return true;
        if(j == m) return false;
        if(i == n) {
            while(j < m) {
                if(j+1 == m || p[j+1] != '*') return false;
                j+=2;
            }
            return true;
        }

        if (j+1 < m && p[j+1] == '*') {
            bool no_match = solve(s,p,i,j+2);
            bool match = false;
            if(p[j] == s[i] || p[j] == '.') match = solve(s,p,i+1,j);
            return no_match || match;
        }
        if(s[i] == p[j] || p[j] == '.') return solve(s,p,i+1,j+1);

        return false;
    }

    bool isMatch(string s, string p) {
        n = s.length(), m = p.length();
        return solve(s,p,0,0);
    }
};