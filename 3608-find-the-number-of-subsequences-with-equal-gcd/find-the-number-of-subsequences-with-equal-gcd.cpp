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

    int subcount (vector<int>& nums, int idx, int g1, int g2, vector<vector<vector<int>>> &dp) {
        if(idx == n) {
            if(g1 == g2 && g1 != 0) return 1;
            return 0;
        }
        if(dp[idx][g1][g2] != -1) return dp[idx][g1][g2];

        int skip = subcount(nums,idx+1,g1,g2,dp);
        int take1 = subcount(nums,idx+1,gcd(g1,nums[idx]),g2,dp);
        int take2 = subcount(nums,idx+1,g1,gcd(g2,nums[idx]),dp);

        return dp[idx][g1][g2] = ((skip + take1) % mod + take2) % mod;
    }

    int subsequencePairCount(vector<int>& nums) {
        n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        vector<vector<vector<int>>> dp (n, vector<vector<int>> (maxi+1 , vector<int> (maxi+1,-1)));
        return subcount(nums,0,0,0,dp);
    }
};