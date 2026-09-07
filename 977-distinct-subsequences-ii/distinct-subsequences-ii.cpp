class Solution {
public:
    const long mod = 1e9 + 7;
    int distinctSubseqII(string s) {
        int n = s.length();

        vector<int> lastIdx (26,0);
        int prev = 0;

        for(int i = 1; i<=n; i++) {
            int temp = (2 * (long long)prev + 1) % mod;
            temp = (temp - lastIdx[s[i-1] - 'a'] + mod) % mod;
            lastIdx[s[i-1] - 'a'] = prev + 1;
            prev = temp;
        }

        return prev;
    }
};