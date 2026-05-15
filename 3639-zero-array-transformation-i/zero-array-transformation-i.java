class Solution {
    public boolean isZeroArray(int[] nums, int[][] queries) {
        int[] diff = new int[nums.length];

        for(int i = 0; i<queries.length; i++) {
            diff[queries[i][0]]--;
            if(queries[i][1] + 1 < diff.length) diff[queries[i][1]+1]++;
        }
        
        int cumsum = 0;

        for(int i = 0; i<diff.length; i++) {
            cumsum += diff[i];
            if(nums[i] + cumsum > 0) return false;
        }

        return true;
    }
}