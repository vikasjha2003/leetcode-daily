class Solution {
public:
    int largestInteger(int n, int s) {
        int start = pow(10,n)-1;
        while(start >= 0) {
            int a = start;
            int sum = 0;
            while(a > 0) {
                sum += a % 10;
                a /= 10;
            }

            if(sum == s) return start;
            start--;
        }

        return -1;
    }
};