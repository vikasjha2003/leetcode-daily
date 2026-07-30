class Solution {
public:
    int minimumPushes(string word) {
        int res = 0;

        for(int i = 0; i<word.length(); i++) {
            if(i < 8) res++;
            else if (i < 16) res += 2;
            else if (i < 24) res += 3;
            else res += 4;
        }

        return res;
    }
};