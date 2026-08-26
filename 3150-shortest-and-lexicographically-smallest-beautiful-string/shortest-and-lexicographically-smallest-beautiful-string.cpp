class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        int r = 0;
        string res = s + "a";
        string str = "";

        while(r < n) {
            str += s[r];
            if(s[r] == '1') k--;

            while(k == 0) {
                if(str.length() < res.length()) {
                    res = str;
                } else if (str.length() == res.length() && str < res) {
                    res = str;
                }
                if(str[0] == '1') k++;
                str.erase(0,1);
            }

            r++;
        }

        return res.length() == n+1 ? "" : res;
    }
};