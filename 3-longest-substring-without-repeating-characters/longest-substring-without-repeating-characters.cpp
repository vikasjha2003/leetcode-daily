class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen = 0;
        unordered_set<int> st;
        int l = 0;
        int r = 0;
        while(r<s.length()) {
            if(st.find(s[r]) == st.end()) st.insert(s[r]);
            else {
                while(st.find(s[r]) != st.end()) {
                    st.erase(s[l]);
                    l++;
                }
                st.insert(s[r]);
            }
            maxlen = max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
};