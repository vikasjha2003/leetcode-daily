class Solution {
public:
    long long sumAndMultiply(int n) {
        int sum = 0;
        int x = 0;
        int i = 1;
        while(n>0) {
            int a = n%10;
            if(a != 0) {
                x += a*i;
                sum += a;
                i *= 10;
            }
            n /= 10;
        }
        return (long long) x * sum;
    }
};