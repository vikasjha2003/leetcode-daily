class Solution {
public:
    int gcd (int a, int b) {
        while (b!= 0) {
            int temp = b;
            b = a%b;
            a = temp;
        }
        return a;
    }
    int gcdOfOddEvenSums(int n) {
        int es = 0 , os = 0;
        for(int i = 1; i<=2*n; i++) {
            if(i%2 == 0) es += i;
            else os += i;
        }
        return gcd(es,os);
    }
};