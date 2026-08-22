class Solution {
public:
    bool checkDivisibility(int n) {
        int digiSum = 0;
        int digiProd = 1;
        int a = n;
        while(a > 0) {
            digiSum += a%10;
            digiProd *= a%10;
            a /= 10;
        }

        return n % (digiProd + digiSum) == 0 ? true : false;
    }
};