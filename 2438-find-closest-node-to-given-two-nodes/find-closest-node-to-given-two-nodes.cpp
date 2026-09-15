class Solution {
public:
    void DFS(vector<int>& edges, int node, vector<int> &dist, int cnt) {
        if(node == -1 || dist[node] != -1) return;
        dist[node] = cnt;
        DFS(edges,edges[node],dist,cnt+1);
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();

        vector<int> dist1 (n,-1);
        vector<int> dist2 (n,-1);
        DFS(edges,node1,dist1,0);
        DFS(edges,node2,dist2,0);

        int result = -1;
        int dist = INT_MAX;

        for(int i = 0; i<n; i++) {
            if(dist1[i] != -1 && dist2[i] != -1) {
                int maxd = max(dist1[i],dist2[i]);
                if(maxd < dist) {
                    dist = maxd;
                    result = i;
                } 
            }
        }

        return result;
    }
};