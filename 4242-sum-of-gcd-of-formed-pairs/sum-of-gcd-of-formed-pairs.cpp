class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();

        int maxi = INT_MIN;
        vector<int> pgcd(n,0);

        for(int i = 0; i<n; i++) {
            maxi = max(maxi,nums[i]);
            pgcd[i] = gcd(maxi,nums[i]);
        }

        sort(pgcd.begin(),pgcd.end());

        int l = 0;
        int r = n-1;
        long long res = 0;

        while(l < r) {
            res += gcd(pgcd[l],pgcd[r]);
            l++;
            r--;
        }

        return res;
    }
};