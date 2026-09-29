class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj (n+1);
        for(auto & time : times) {
            adj[time[0]].push_back({time[1],time[2]});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist (n+1,INT_MAX);
        pq.push({0,k});
        dist[k] = 0;

        while(!pq.empty()) {
            auto [dis,u] = pq.top();
            pq.pop();

            if(dis > dist[u]) continue;

            for(auto [v,w] : adj[u]) {
                if(w + dis < dist[v]) {
                    pq.push({w+dis,v});
                    dist[v] = w+dis;
                }
            }
        }

        int mintime = 0;
        for(int i = 1; i<=n; i++) {
            if(dist[i] == INT_MAX) return -1;
            mintime = max(mintime,dist[i]);
        }

        return mintime;
    }
};