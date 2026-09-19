class Solution {
public:
    string simplifyPath(string path) {
        string res = "";
        int cnt = 0;
        bool flag = true;
        for(char c : path) {
            if((cnt == 1 || cnt == 2) && c == '/') {
                while(cnt > 0 && res.size() > 1) {
                    if(res.back() == '/') cnt--;
                    res.pop_back();
                }
                cnt = 0;
            } else if (cnt > 0 && c != '.') {
                cnt = 0;
            }

            if(c == '/' && !res.empty() && res.back() == '/') continue;

            if(c == '.' && res.back() != '.' && res.back() != '/') {
                flag = false;
            } else if (c == '.' && flag) {
                cnt++;
            }

            if(c == '/' && !flag) flag = !flag;

            res.push_back(c);
        }

        if(cnt == 1 || cnt == 2) {
            while(cnt > 0 && res.size() > 1) {
                if(res.back() == '/') cnt--;
                res.pop_back();
            }
        }

        if(res.size() > 1 && res.back() == '/') res.pop_back();

        return res;
    }
};