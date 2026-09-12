class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();

        vector<int> suffixO (n+1,0);
        vector<int> suffixE (n+1,0);
        int sumo = 0, sume = 0;

        for(int i = n-1; i>= 0; i--) {
            if(i%2==0) sume += nums[i];
            else sumo += nums[i];

            suffixE[i] += sume;
            suffixO[i] += sumo;
        }

        int ways = 0;

        sumo = 0;
        sume = 0;

        for(int i = 0; i<n; i++) {
            if(sume + suffixO[i+1] == sumo + suffixE[i+1]) ways++;

            if(i%2==0) sume += nums[i];
            else sumo += nums[i];
        }
        
        return ways;
    }
};