class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        int bestBuy = INT_MAX;
        for(int i : prices) {
            if(i < bestBuy) bestBuy = i;
            else {
                result += i - bestBuy;
                bestBuy = i;
            }
        }

        return result;
    }
};