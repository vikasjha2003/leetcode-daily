class Solution {
    public int[] copyOf (int[] nums, int l, int r) {
        int[] arr = new int[r-l+1];
        for(int i = 0; i <= r - l; i++) {
            arr[i] = nums[i+l];
        }
        return arr;
    }
    public List<Boolean> checkArithmeticSubarrays(int[] nums, int[] l, int[] r) {
        int m = l.length;
        int n = nums.length;

        List<Boolean> ans = new ArrayList<>();

        for(int i = 0; i<m; i++) {
            int[] arr = copyOf(nums,l[i],r[i]);
            Arrays.sort(arr);
            Boolean flag = true;
            int x = arr[1] - arr[0];
            for(int j = 2; j<arr.length; j++) {
                if(arr[j] - arr[j-1] != x) {
                    flag = false;
                    break;
                }
            }
            ans.add( flag);
        }

        return ans;
    }
}