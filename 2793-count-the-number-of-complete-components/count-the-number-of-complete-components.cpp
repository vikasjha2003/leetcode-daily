class Solution {
public:

    void DFS (vector<vector<int>> &adj, vector<int> &visited, vector<pair<int,int>> &bucket, int node) {
        visited[node] = true;
        bucket.push_back({node,adj[node].size()});

        for(int next : adj[node]) {
            if(!visited[next]) {
                DFS(adj,visited,bucket,next);
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
                DFS(adj,visited,bucket,i);

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