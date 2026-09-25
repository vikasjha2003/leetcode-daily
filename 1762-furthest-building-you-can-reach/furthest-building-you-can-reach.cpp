class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();

        priority_queue<int, vector<int>, greater<int>> pq;
        int i = 0;
        while(i < n-1) {
            if(heights[i+1] > heights[i]) {
                if(ladders > 0) {
                    pq.push(heights[i+1]-heights[i]);
                    ladders--;
                } else {
                    int val = heights[i+1] - heights[i];
                    if(!pq.empty() && val > pq.top()) {
                        if(bricks < pq.top()) return i;
                        bricks -= pq.top();
                        pq.pop();
                        pq.push(val);
                    } else {
                        if(bricks < val) return i;
                        bricks -= val;
                    }
                }
            }
            i++;
        }
        return i;
    }
};