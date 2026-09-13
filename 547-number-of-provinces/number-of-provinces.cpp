class Solution {
private:
    vector<int> size , parent;
public:
    int findParent(int node) {
        if(parent[node] == node) return node;
        return parent[node] = parent[parent[node]];
    }
    void unionBySize(int u, int v) {
        int parentU = findParent(u);
        int parentV = findParent(v);

        if(parentU == parentV) return;

        if(size[parentU] < size[parentV]) {
            parent[parentU] = parentV;
            size[parentV] += size[parentU];
        } else {
            parent[parentV] = parentU;
            size[parentU] += size[parentV];
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<vector<int>> adj (n);
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                if(i != j && isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                }
            }
        }

        size.resize(n,1);
        parent.resize(n);
        for(int i = 0; i<n; i++) {
            parent[i] = i;
        }

        for(int u = 0; u<n; u++) {
            for(int v : adj[u]) {
                unionBySize(u,v);
            }
        }

        int result = 0;
        for(int i = 0; i<n; i++) {
            if(i == parent[i]) result++;
        }
        
        return result;
    }
};