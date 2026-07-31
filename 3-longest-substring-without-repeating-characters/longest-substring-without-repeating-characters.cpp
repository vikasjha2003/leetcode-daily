class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();

        int left = 0;
        int right = 0;
        int maxLen = 0;

        unordered_set<char> st;

        while(right < n) {
            if(st.find(s[right]) == st.end()) {
                st.insert(s[right]);
                right++;
                maxLen = max(right - left,maxLen);
            } else {
                while(st.find(s[right]) != st.end()) {
                    st.erase(s[left]);
                    left++;
                }
            }
        }

        return maxLen;
    }
};