class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = nums.size();
        int res = 0;
        float val = float(a) / b;
        for(int i = 0; i<n; i++) {
            int eCnt = 0;
            int oCnt = 0;
            for(int j = i; j<n; j++) {
                if(nums[j] % 2 == 1) oCnt++;
                else eCnt++;
                if(oCnt > 0 && float(eCnt) / oCnt <= val) {
                    res++;
                }
            }
        }
        return res;
    }
};