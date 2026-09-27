class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj (n);
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                if(isConnected[i][j] == 1) adj[i].push_back(j);
            }
        }

        vector<int> visited(n,0);
        int provinces = 0;
        for(int i = 0; i<n; i++) {
            if(!visited[i]) {
                visited[i] = 1;
                provinces++;
                queue<int> q;
                q.push(i);
                while(!q.empty()) {
                    int node = q.front();
                    q.pop();
                    for(int it : adj[node]) {
                        if(!visited[it]) {
                            visited[it] = 1;
                            q.push(it);
                        }
                    }
                }
            }
        }

        return provinces;
    }
};