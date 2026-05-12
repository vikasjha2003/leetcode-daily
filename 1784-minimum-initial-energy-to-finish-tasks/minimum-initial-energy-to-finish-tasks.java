class Solution {
    public int minimumEffort(int[][] tasks) {
        Arrays.sort(tasks, (a,b) -> Integer.compare(b[1] - b[0] , a[1] - a[0]));

        int start = tasks[0][1];
        int sum = tasks[0][1] - tasks[0][0];        
        int res = 0;

        for(int i = 1; i<tasks.length; i++) {
            if(sum < tasks[i][1]) {
                res += tasks[i][1] - sum;
                sum = tasks[i][1];
            }
            sum -= tasks[i][0];
        }

        return start + res;
    }
}