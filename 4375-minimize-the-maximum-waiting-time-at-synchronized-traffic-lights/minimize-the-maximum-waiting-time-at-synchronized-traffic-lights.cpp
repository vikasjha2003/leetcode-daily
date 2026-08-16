class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int n = arrivalTime.size();

        int light = *max_element(lights.begin(),lights.end());

        int minPenalty = 0;

        for(int i = 0; i < n; i++) {
            int r = arrivalTime[i] % period;
            if(r >= light) {
                minPenalty = max(minPenalty,period - r);
            }
        }

        return minPenalty;
    }
};