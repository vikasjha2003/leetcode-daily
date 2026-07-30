class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Horizontal and vertical
        for(int i = 0; i<9; i++) {
            unordered_set<int> st;
            for(int j = 0; j<9; j++) {
                if(board[i][j] == '.') continue;
                if(st.find(board[i][j]) != st.end()) return false;
                st.insert(board[i][j]);
            }
            
            unordered_set<int> s;
            for(int j = 0; j<9; j++) {
                if(board[j][i] == '.') continue;
                if(s.find(board[j][i]) != s.end()) return false;
                s.insert(board[j][i]);
            }
        }

        // box
        for(int i = 0; i<9; i+=3) {
            for(int j = 0; j<9; j+=3) {
                unordered_set<int> st;
                for(int row = i; row < i + 3; row++) {
                    for(int col = j; col < j + 3; col++) {
                        if(board[row][col] == '.') continue;
                        if(st.find(board[row][col]) != st.end()) return false;
                        st.insert(board[row][col]);
                    }
                }
            }
        }

        return true;
    }
};