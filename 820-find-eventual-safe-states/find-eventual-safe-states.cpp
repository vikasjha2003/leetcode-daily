class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<vector<int>> adj (n);
        vector<int> outdegree (n,0);
        for(int i = 0; i<n; i++) {
            outdegree[i] = graph[i].size();
            for(int j = 0; j<graph[i].size(); j++) {
                adj[graph[i][j]].push_back(i);
            }
        }

        queue<int> q;
        for(int i = 0; i<n; i++) {
            if(outdegree[i] == 0) q.push(i);
        }

        vector<int> res;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            res.push_back(node);
            for(int i : adj[node]) {
                outdegree[i]--;
                if(outdegree[i] == 0) q.push(i);
            }
        }

        sort(res.begin(),res.end());
        return res;
    }
};