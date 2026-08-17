class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        string res = "";
        
        int cnt = 0;
        for(char c : s) {
            if(c != x) res.push_back(c);
            else cnt++;
        }

        while(cnt--) {
            res.push_back(x);
        }

        return res;
    }
};