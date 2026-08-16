class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int n = arrivalTime.size();

        int light = *max_element(lights.begin(),lights.end());

        int Penalty = 0;

        for(int i = 0; i < n; i++) {
            int r = arrivalTime[i] % period;
            if(r >= light) {
                Penalty = max(Penalty,period - r);
            }
        }

        return Penalty;
    }
};