class Solution {
private:
    vector<int> size, parent;
public:
    int findParent(int node) {
        if(parent[node] == node) return node;
        return parent[node] = findParent(parent[node]);
    }
    void unionByRank(int u, int v, int &cnt) {
        int pu = findParent(u);
        int pv = findParent(v);

        if(pu == pv) {
            cnt++;
            return;
        }

        if(size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        size.resize(n,1);
        parent.resize(n);
        for(int i = 0; i<n; i++) {
            parent[i] = i;
        }

        int cntA = 0;
        for(int i = 0; i<connections.size(); i++) {
            unionByRank(connections[i][0],connections[i][1],cntA);
        }

        int cntN = 0;
        for(int i = 0; i<n; i++) {
            if(parent[i] == i) cntN++;
        }

        if(cntA < cntN - 1) return -1;
        return min(cntA,cntN-1);   
    }
};