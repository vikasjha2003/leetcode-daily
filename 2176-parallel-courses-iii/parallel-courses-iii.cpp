class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adj (n);
        vector<int> indegree (n,0);
        for(auto& relation : relations) {
            adj[relation[0]-1].push_back(relation[1]-1);
            indegree[relation[1]-1]++;
        }

        queue<int> q;
        vector<int> finish (n);
        for(int i = 0; i<n; i++) {
            if(indegree[i] == 0) q.push(i);
            finish[i] = time[i];
        }

        int ans = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans = max(ans,finish[node]);
            for(int i : adj[node]) {
                finish[i] = max(finish[i],finish[node] + time[i]);
                indegree[i]--;
                if(indegree[i] == 0) q.push(i);
            }
        }
        
        return ans;
    }
};