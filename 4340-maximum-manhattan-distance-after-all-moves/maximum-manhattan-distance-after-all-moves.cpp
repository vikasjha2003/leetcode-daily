class Solution {
public:
    int maxDistance(string moves) {
        int vertical = 0, horizontal = 0, extra = 0;
        for(char c : moves) {
            if(c == 'U') {
                vertical++;
            } else if (c == 'D') {
                vertical--;
            } else if (c == 'R') {
                horizontal++;
            } else if (c == 'L') {
                horizontal--;
            } else {
                extra++;
            }
        }
        
        return abs(vertical) + abs(horizontal) + extra;
    }
};