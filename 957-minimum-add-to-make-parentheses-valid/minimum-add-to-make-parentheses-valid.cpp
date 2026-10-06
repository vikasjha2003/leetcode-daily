class Solution {
public:
    int minAddToMakeValid(string s) {
        int res = 0;
        int cnt = 0;
        for(char c : s) {
            if(c == '(') cnt++;
            else cnt--;

            if(cnt < 0) {
                res++;
                cnt++;
            }

        }

        return res + abs(cnt);
    }
};