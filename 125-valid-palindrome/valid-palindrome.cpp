class Solution {
public:
    bool isAlphaNumeric (char c) {
        return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }
    bool isPalindrome(string s) {
        int n = s.length();

        string str = "";
        for(int i = 0; i<n; i++) {
            if(isAlphaNumeric(s[i])) {
                if(s[i] >= 'A' && s[i] <= 'Z') {
                    str += s[i] + 32;
                } else {
                    str += s[i];
                }
            }
        }

        int l = 0;
        int r = str.length()-1;

        while(l < r) {
            if(str[l] != str[r]) return false;
            l++;
            r--;
        }

        return true;
    }
};