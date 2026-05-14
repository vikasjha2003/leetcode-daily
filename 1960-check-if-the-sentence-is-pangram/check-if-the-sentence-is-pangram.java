class Solution {
    public boolean checkIfPangram(String sentence) {
        Set<Character> st = new HashSet<>();
        for(int i = 0; i<sentence.length(); i++) {
            char c = sentence.charAt(i);
            st.add(c);
        }

        return st.size() == 26 ? true : false;
    }
}