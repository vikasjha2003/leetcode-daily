class Solution {
public:
    int n;
    const int mod = 1e9 + 7;

    int gcd (int a , int b) {
        if(a == 0) return b;

        while(b != 0) {
            int temp = b;
            b = a%b;
            a = temp;
        }
        return a;
    }

    int subsequencePairCount(vector<int>& nums) {
        n = nums.size();

        int maxi = *max_element(nums.begin(), nums.end());
        vector<vector<vector<int>>> dp (n+1 ,vector<vector<int>> (maxi+1 ,vector<int> (maxi+1,0)));
        
        for(int i = 0; i<= maxi; i++) {
            dp[n][i][i] = 1;
        }

        for(int i = n-1; i>= 0; i--) {
            for(int j = 0; j<= maxi; j++) {
                for(int k = 0; k<= maxi; k++) {
                    int skip = dp[i+1][j][k];
                    int take1 = dp[i+1][gcd(j,nums[i])][k];
                    int take2 = dp[i+1][j][gcd(k,nums[i])];

                    dp[i][j][k] = ((skip + take1) % mod + take2) % mod;
                }
            }
        }

        return dp[0][0][0] -1;
    }
};