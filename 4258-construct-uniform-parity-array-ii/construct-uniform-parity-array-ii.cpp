class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mini = INT_MAX;
        bool odd = false;
        for(auto it : nums1){
            
            if(it%2){
                odd=true;
                mini=min(mini,it);
            }
        }
        
        if(!odd) return true;
        for(int it : nums1){
            if(it%2==0 && mini>it) return false;
        }

        return true;
    }
};