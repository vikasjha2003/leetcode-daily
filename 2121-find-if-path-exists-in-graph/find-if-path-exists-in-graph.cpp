class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(n == 1) return true;
        vector<vector<int>> adj(n);
        for(auto &it : edges) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> visited(n,0);
        queue<int> q;
        q.push(source);
        visited[source] = 1;
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(int next : adj[node]) {
                if(next == destination) return true;
                if(!visited[next]) {
                    visited[next] = 1;
                    q.push(next);
                }
            }
        }

        return false;
    }
};