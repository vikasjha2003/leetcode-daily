class Solution {
public:
    int n;
    bool solve(vector<int>& stones, int idx, int target) {
        if(target == 0) return true;
        if(idx == n) return false;

        if(solve(stones,idx+1,target)) return true;
        if(stones[idx] <= target && solve(stones,idx+1,target-stones[idx])) return true;

        return false;
    }
    int lastStoneWeightII(vector<int>& stones) {
        n = stones.size();

        int sum = accumulate(stones.begin(),stones.end(),0);

        for(int i = sum/2; i>0; i--) {
            if(solve(stones,0,i)) return sum - 2*i;
        }
        
        return sum;
    }
};