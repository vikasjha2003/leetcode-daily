class Solution {
public:
    int reverseDegree(string s) {
        int res = 0;
        for(int i = 0; i<s.length(); i++) {
            int val = 26 - (s[i] - 'a');
            res += val * (i+1);
        }
        return res;
    }
};