class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int i : stones) {
            pq.push(i);
        }

        while(pq.size() > 1) {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            int val = abs(x-y);
            if(val != 0) pq.push(val);
        }
        if(pq.size() == 0) return 0;
        return pq.top();
    }
};