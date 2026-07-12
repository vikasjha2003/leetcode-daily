class Solution {
public:

    void BFS (vector<vector<int>> &adj, vector<int> &visited, 
    vector<pair<int,int>> &bucket, int node) {

        queue<int> q;
        q.push(node);
        visited[node] = true;
        bucket.push_back({node,adj[node].size()});

        while(!q.empty()) {
            int cur = q.front();
            q.pop();

            for(int next : adj[cur]) {
                if(!visited[next]) {
                    q.push(next);
                    visited[next] = true;
                    bucket.push_back({next,adj[next].size()});
                }
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj (n);
        for(int i = 0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> visited (n,false);

        int res = 0;

        for(int i = 0; i<n; i++) {
            if(!visited[i]) {
                vector<pair<int,int>> bucket;
                BFS(adj,visited,bucket,i);

                int a = bucket[0].second;

                if(a == bucket.size() - 1) {
                    bool flag = true;
                    for(auto &it : bucket) {
                        if(it.second != a) {
                            flag = false;
                            break;
                        }
                    }

                    if(flag) res++;
                }
            }
        }

        return res;
    }
};