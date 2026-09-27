class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> visited(n,0);
        unordered_set<int> A;
        unordered_set<int> B;

        for(int i = 0; i<n; i++) {
            if(!visited[i]) {
                visited[i] = 1;
                bool flag = true;
                A.insert(i);
                queue<int> q;
                q.push(i);
                while(!q.empty()) {
                    int sz = q.size();
                    while(sz--) {
                        int node = q.front();
                        q.pop();
                        for(int i : graph[node]) {
                            if(flag && A.find(i) != A.end()) return false;
                            if(!flag && B.find(i) != B.end()) return false;
                            if(!visited[i]) {
                                if(flag) {
                                    B.insert(i);
                                } else {
                                    A.insert(i);
                                }
                                visited[i] = 1;
                                q.push(i);
                            }
                        }
                    }
                    flag = !flag;
                }
            }
        }

        return true;
    }
};