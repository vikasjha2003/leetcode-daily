class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();
        int l = 0, maxLen = 0;

        int freq[26] = {0};

        for(int i = 0; i<n; i++) {
            freq[s[i] - 'a']++;
            while(freq[s[i] - 'a'] > 2) {
                freq[s[l] - 'a']--;
                l++;
            }

            maxLen = max(maxLen,(i-l+1));
        }

        return maxLen;
    }
};