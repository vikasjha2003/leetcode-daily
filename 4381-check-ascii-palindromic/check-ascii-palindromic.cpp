class Solution {
public:
    bool isPalindrome(string &str) {
        int i = 0;
        int j = str.length()-1;
        while(i < j) {
            if(str[i] != str[j]) return false;
            i++;
            j--;
        }

        return true;
    }

    bool isPalindromic(string s) {
        string res = "";
        for(char c : s) {
            string cur = "00000000";
            int idx = 7;
            int a = c;
            while(a > 0) {
                if(a % 2 == 1) cur[idx] = '1';
                idx--;
                a /= 2;
            }

            res += cur;
        }

        return isPalindrome(res);
    }
};