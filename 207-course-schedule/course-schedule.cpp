class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        int m = prerequisites.size();

        vector<int> indegree(n,0);
        vector<vector<int>> adj (n);

        for(int i = 0; i<m; i++) {
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];

            indegree[a]++;
            adj[b].push_back(a);
        }

        queue<int> q;
        for(int i = 0; i<n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        if(q.empty()) return false;

        vector<int> ans;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(int i : adj[node]) {
                indegree[i]--;
                if(indegree[i] == 0) {
                    q.push(i);
                }
            }
        }

        if(ans.size() == n) return true;
        return false;
    }
};