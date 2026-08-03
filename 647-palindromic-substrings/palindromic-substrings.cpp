class Solution {
public:

    bool isPalindrome(string &s) {
        int i = 0;
        int j = s.length() -1;
        while(i < j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }

        return true;
    }

    int countSubstrings(string s) {
        int n = s.length();

        int cnt = 0;
        for(int i = 0; i<n; i++) {
            string str = "";
            for(int j = i; j<n; j++) {
                str += s[j];
                if(isPalindrome(str)) cnt++;
            }
        }

        return cnt;
    }
};