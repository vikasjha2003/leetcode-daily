class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<pair<int,int>> pos;
        for(int i = 0; i<n; i++) {
            int num = nums[i];
            int sum = 0;
            while(num > 0) {
                sum += num % 10;
                num /= 10;
            }
            pos.push_back({sum,i});
        }

        sort(pos.begin(),pos.end(),[&](const auto &p1 , const auto &p2) {
            if(p1.first == p2.first) return nums[p1.second] < nums[p2.second];
            return p1.first < p2.first;
        });

        unordered_set<int> st;
        int cnt = 0;
        for(int i = 0; i<n; i++) {
            if(st.find(i) != st.end()) continue;
            int idx = pos[i].second;
            if(idx == i) continue;
            else {
                int cur = 0;
                while(st.find(idx) == st.end()) {
                    st.insert(idx);
                    idx = pos[idx].second;
                    cur++;
                }

                cnt = cnt + cur - 1;
            }
        }

        return cnt;
    }
};