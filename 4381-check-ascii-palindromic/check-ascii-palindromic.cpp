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
        string binary = "";
        for(char c : s) {
            int a = c;
            
            string cur = bitset<8>(a).to_string();

            binary += cur;
        }

        return isPalindrome(binary);
    }
};