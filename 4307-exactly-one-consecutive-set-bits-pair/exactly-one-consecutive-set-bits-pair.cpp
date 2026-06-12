class Solution {
public:
    bool consecutiveSetBits(int n) {
        int cnt = 0;
        bool flag = false;
        while(n > 0) {
            if(n % 2== 1) {
                cnt++;
                if(flag == false && cnt == 2) {
                    flag = true;
                } else if (flag == true && cnt >= 2) {
                    return false;
                }
            } else {
                cnt = 0;
            }
            n /= 2;
        }

        return flag;
    }
};