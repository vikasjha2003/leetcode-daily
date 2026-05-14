class Solution {
    public String shiftingLetters(String s, int[][] shifts) {
        int[] diff = new int[s.length()];

        for(int[] q : shifts) {
            int a = 1;
            if(q[2] == 0) a = -1;
            diff[q[0]] += a;
            if(q[1] + 1 < diff.length) diff[q[1] + 1] -= a; 
        }

        char[] sb = s.toCharArray();
        int cumsum = 0;

        for(int i = 0; i<diff.length; i++) {
            cumsum += diff[i];
            int a = cumsum + (s.charAt(i) - 'a');
            int mod = (a % 26 + 26) % 26;
            sb[i] = (char)(mod + 'a');
        }

        return new String(sb);
    }
}