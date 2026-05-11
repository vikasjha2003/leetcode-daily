class Solution {
    public int wateringPlants(int[] plants, int capacity) {
        int cur = capacity;
        int res = 0;
        for(int i = 0; i<plants.length; i++) {
            cur -= plants[i];            
            if(i+1 < plants.length && plants[i+1] > cur) {
                cur = capacity;
                res += (i+1)*2;
            }
            res++;
        }
        return res;
    }
}