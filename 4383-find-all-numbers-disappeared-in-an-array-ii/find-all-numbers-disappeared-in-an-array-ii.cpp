class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        unordered_set<int> st;
        for(int num : nums) {
            st.insert(num);
        }

        vector<vector<int>> result;

        for(int i = lower; i<= upper; i++) {
            if(st.find(i) == st.end()) {
                int j = i;
                while(j <= upper && st.find(j) == st.end()) {
                    j++;
                }
                result.push_back({i,j-1});
                i = j;
            }
        }

        return result;
    }
};