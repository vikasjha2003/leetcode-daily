class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();

        string str = s;
        str.push_back('a');

        for(int i=0; i<n; i++) {
            int cnt = 0;
            string st = "";
            for(int j = i; j<n; j++) {
                if(s[j] == '1') cnt++;
                st += s[j];

                if(cnt == k) {
                    if(st.length() < str.length()) {
                        str = st;
                    } else if (st.length() == str.length() && st < str) {
                        str = st;
                    }

                    break;
                }
            }
        }

        return str.length() == n+1 ? "" : str;
    }
};