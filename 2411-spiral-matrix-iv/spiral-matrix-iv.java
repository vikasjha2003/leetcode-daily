/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public int[][] spiralMatrix(int m, int n, ListNode head) {
        int[][] grid = new int[m][n];

        int rows = 0, rowe = m-1, cols = 0, cole = n-1;

        while(rows <= rowe && cols <= cole) {
            for(int i = cols; i <= cole; i++) {
                if(head != null) {
                    grid[rows][i] = head.val;
                    head = head.next;
                } else grid[rows][i] = -1;
            }
            rows++;
            for(int i = rows; i <= rowe; i++) {
                if(head != null) {
                    grid[i][cole] = head.val;
                    head = head.next;
                } else grid[i][cole] = -1;
            }
            cole--;
            if(rows <= rowe) {
                for(int i = cole; i >= cols; i--) {
                    if(head != null) {
                        grid[rowe][i] = head.val;
                        head = head.next;
                    } else grid[rowe][i] = -1;
                }
                rowe--;
            }
            if(cols <= cole) {
                for(int i = rowe; i >= rows; i--) {
                    if(head != null) {
                        grid[i][cols] = head.val;
                        head = head.next;
                    } else grid[i][cols] = -1;
                }
                cols++;
            }
        }

        return grid;
    }
}