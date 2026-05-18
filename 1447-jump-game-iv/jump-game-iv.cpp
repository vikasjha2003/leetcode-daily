class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return 0;

        unordered_map<int,vector<int>> pos;
        for(int i = 0; i<n; i++) {
            pos[arr[i]].push_back(i);
        }

        vector<bool> vis (n,false);
        int cnt = 0;

        queue<int> q;
        q.push(0);
        vis[0] = true;

        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                int idx = q.front();
                q.pop();

                if(idx == n-1) return cnt;
                if(idx-1 >= 0 && !vis[idx-1]) {
                    q.push(idx-1);
                    vis[idx-1] = true;
                }
                if(idx+1 < n && !vis[idx+1]) {
                    q.push(idx+1);
                    vis[idx+1] = true;
                }
                for(int &val : pos[arr[idx]]) {
                    if(!vis[val]) {
                        q.push(val);
                        vis[val] = true;
                    }
                }
                pos[arr[idx]].clear();
            }
            cnt++;
        }

        return -1;
    }
};