class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();

        int idx = 0;
        int cnt = 1;
        for(int i = 1; i<n; i++) {
            if(chars[i] == chars[i-1]) {
                cnt++;
            } else {
                if(cnt == 1) {
                    chars[idx++] = chars[i-1];
                } else if (cnt < 10) {
                    chars[idx++] = chars[i-1];
                    chars[idx++] = (char)(cnt+48);
                    cnt = 1;
                } else {
                    chars[idx++] = chars[i-1];
                    string st = to_string(cnt);
                    for(char c : st) {
                        chars[idx++] = c;
                    }
                    cnt = 1;
                }
            }
        }

        if(cnt == 1) {
            chars[idx++] = chars.back();
        } else if (cnt < 10) {
            chars[idx++] = chars.back();
            chars[idx++] = (char)(cnt+48);
        } else {
            chars[idx++] = chars.back();
            string st = to_string(cnt);
            for(char c : st) {
                chars[idx++] = c;
            }
        }

        return idx;
    }
};