class Solution {
public:
    int n;
    int solve(vector<int>& digits, int num, vector<int> &used, unordered_set<int> &st) {
        if(num > 99 && num % 2 == 0) {
            if(st.find(num) == st.end()) {
                st.insert(num);
                return 1;
            }
        }
        if(num > 99) return 0;

        int cnt = 0;

        for(int i = 0; i<n; i++) {
            if(!used[i]) {
                used[i] = true;
                cnt += solve(digits,num*10+digits[i],used,st);
                used[i] = false;
            }
        }

        return cnt;
    }
    int totalNumbers(vector<int>& digits) {
        n = digits.size();
        vector<int> used (n,false);
        unordered_set<int> st;
        return solve(digits,0,used,st);
    }
};