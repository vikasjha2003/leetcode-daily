class Solution {
public:
    bool isPredecessor(string &s1, string &s2) {
        if(s2.length() - s1.length() != 1) return false;
        bool flag = false;
        int i = 0, j = 0;
        while(i < s1.length()) {
            if(s1[i] == s2[j]) {
                i++;
                j++;
            } else {
                if(flag) return false;
                flag = true;
                j++;
            }
        }
        return true;
    }

    int n;
    vector<vector<int>> dp;

    int solve(vector<string>& words, int idx, int last) {
        if(idx == n) return 0;
        if(dp[idx][last+1] != -1) return dp[idx][last+1];

        int skip = solve(words,idx+1,last);

        int take = 0;
        if(last == -1 || isPredecessor(words[last],words[idx])) {
            take = 1 + solve(words,idx+1,idx);
        }

        return dp[idx][last+1] = max(skip,take);
    }

    int longestStrChain(vector<string>& words) {
        n = words.size();
        sort(words.begin(),words.end(),[](string& s1, string& s2) {
            return s1.length() < s2.length();
        });
        dp.resize(n, vector<int> (n+1,-1));
        return solve(words,0,-1);
    }
};