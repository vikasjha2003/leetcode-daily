class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> check(n,-1);
        for(int i = 0; i<n; i++) {
            if(check[i] == -1) {
                check[i] = 0;
                queue<int> q;
                q.push(i);
                while(!q.empty()) {
                    int node = q.front();
                    q.pop();
                    for(int i : graph[node]) {
                        if(check[i] == -1) {
                            check[i] = !check[node];
                            q.push(i);
                        } else if (check[i] == check[node]) {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};