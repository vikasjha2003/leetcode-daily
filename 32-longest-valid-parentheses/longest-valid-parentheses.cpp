class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();

        int maxLen = 0;
        int cntO = 0;
        int cntC = 0;

        for(int i = 0; i<n; i++) {
            if(s[i] == '(') cntO++;
            else cntC++;

            if(cntO == cntC) maxLen = max(maxLen,cntO * 2);
            if(cntC > cntO) cntO = cntC = 0;
        }

        cntO = 0;
        cntC = 0;
        
        for(int i = n-1; i>=0; i--) {
            if(s[i] == ')') cntC++;
            else cntO++;

            if(cntO == cntC) maxLen = max(maxLen,cntO * 2);
            if(cntO > cntC) cntO = cntC = 0;
        }

        return maxLen;
    }
};