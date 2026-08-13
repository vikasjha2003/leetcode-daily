class Solution {
public:
    int largestInteger(int n, int s) {
        if(9 * n < s) return -1;
        int res = 0;
        for(int i = 1; i<=n; i++) {
            if(s / 9 > 0) {
                s -= 9;
                res = res * 10 + 9;
            } else if (s % 9 != 0) {
                res = res * 10 + s%9;
                s -= s%9;
            } else if (s % 9 == 0) {
                res = res * 10;
            }
        }

        return res;
    }
};