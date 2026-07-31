class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq (26,0);

        for(char c : word) {
            freq[c-'a']++;
        }

        sort(freq.begin(),freq.end(), [](auto &i1 , auto &i2) {
            return i1 > i2;
        });

        int res = 0;

        for(int i = 0; i<26; i++) {
            if(i < 8) res += freq[i];
            else if (i < 16) res += 2 * freq[i];
            else if (i < 24) res += 3 * freq[i];
            else res += 4 * freq[i];
        }

        return res;
        
    }
};