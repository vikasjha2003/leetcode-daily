class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bestBuy = prices[0];
        int maxProfit = 0;

        for(int i = 1; i<prices.size(); i++) {
            maxProfit = max(maxProfit,prices[i]-bestBuy);
            bestBuy = min(prices[i],bestBuy);
        }

        return maxProfit;
    }
};