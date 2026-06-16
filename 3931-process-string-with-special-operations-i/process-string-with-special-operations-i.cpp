class Solution {
public:
    bool isAlphabet(char c) {
        return c >= 'a' && c <= 'z';
    }
    string processStr(string s) {
        string str = "";

        for(char c : s) {
            if(isAlphabet(c)) {
                str.push_back(c);
            } else if (c == '*' && !str.empty()) {
                str.pop_back();
            } else if (c == '#') {
                str += str;
            } else {
                reverse(str.begin(),str.end());
            }
        }

        return str;
    }
};