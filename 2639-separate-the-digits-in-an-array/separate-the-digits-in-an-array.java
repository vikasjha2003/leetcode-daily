class Solution {
    public int[] separateDigits(int[] nums) {
        List<Integer> arr = new ArrayList<>();

        for(int i = 0; i<nums.length; i++) {
            String a = String.valueOf(nums[i]);

            for(int j = 0; j<a.length(); j++) {
                arr.add((a.charAt(j) - '0'));
            }
        }

        int[] res = new int[arr.size()];
        for(int i = 0; i<arr.size(); i++) {
            res[i] = arr.get(i);
        }

        return res;
    }
}