class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length();
        stack<int> p;
        stack<int> a;
        for(int i = 0; i<n; i++) {
            if(s[i] == '(') p.push(i);
            else if (s[i] == '*') a.push(i);
            else {
                if(!p.empty()) {
                    p.pop();
                } else {
                    if(a.empty()) return false;
                    a.pop();
                }
            }
        }

        while(!p.empty() && !a.empty()) {
            if(p.top() < a.top()) {
                a.pop();
                p.pop();
            } else {
                a.pop();
            }
        }

        return p.empty();
    }
};