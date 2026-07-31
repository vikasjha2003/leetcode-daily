class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = 0;
        vector<int> res (n,INT_MAX);

        for(int i = 0; i<n; i++) {
            left = max(left,height[i]);
            res[i] = min(res[i],left);
            right = max(right,height[n-i-1]);
            res[n-i-1] = min(res[n-i-1],right);
        }

        int rain = 0;
        for(int i = 0; i<n; i++) {
            rain += res[i] - height[i];
        }

        return rain;
    }
};