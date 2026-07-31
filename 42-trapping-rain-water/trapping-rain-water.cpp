class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        int right = 0;
        vector<int> rmax (n,INT_MAX);

        for(int i = 0; i<n; i++) {
            right = max(right,height[n-i-1]);
            rmax[n-i-1] = min(rmax[n-i-1],right);
        }

        int rain = 0;
        int lmax = 0;
        for(int i = 0; i<n; i++) {
            lmax = max(height[i],lmax);
            rain += min(rmax[i],lmax) - height[i];
        }

        return rain;
    }
};