class Solution {
public:

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int o = arr2.size();
        unordered_set<string> st;

        int maxlen = 0;

        for(int i = 0; i<n; i++) {
            string s = to_string(arr1[i]);
            int m = s.length();
            string str = "";
            for(int j = 0; j<m; j++) {
                str += s[j];
                st.insert(str);
            }
        }

        for(int i = 0; i<o; i++) {
            string s = to_string(arr2[i]);
            int m = s.length();
            string str = "";
            for(int j = 0; j<m; j++) {
                str += s[j];
                if(st.find(str) != st.end()) {
                    maxlen = max(maxlen,(int)(str.length()));
                } else {
                    break;
                }
            }
        }

       return  maxlen;
    }

};