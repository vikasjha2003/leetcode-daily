class Solution {
    public boolean isGood(int[] nums) {
        Set<Integer> st = new HashSet<>();

        for(int num : nums) {
            if(st.contains(num) && num != nums.length - 1) return false;
            st.add(num);
        }

        if(st.size() != nums.length - 1) return false;

        for(int i = 1; i <= nums.length - 1; i++) {
            if(!st.contains(i)) return false;
        }

        return true;
    }
}