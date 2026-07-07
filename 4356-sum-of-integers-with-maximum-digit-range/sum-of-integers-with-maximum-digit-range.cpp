class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        unordered_map<int,vector<int>> mpp;
        int max_r = 0;

        for(int i : nums) {
            int n = i;
            int maxi = 0;
            int mini = 9;
            while(n > 0) {
                int a = n % 10;

                maxi = max(maxi,a);
                mini = min(mini,a);

                n /= 10;
            }

            max_r = max(max_r, maxi - mini);
            mpp[maxi - mini].push_back(i);
        }

        for(auto &it : mpp) {
            if(it.first == max_r) {
                return accumulate(it.second.begin(), it.second.end(),0);
            }
        }

        return 0;
    }
};