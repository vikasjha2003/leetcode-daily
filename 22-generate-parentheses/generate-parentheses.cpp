class Solution {
public:
    void parent(string st,int n,int no,int nc,vector<string> &v) {
        if(no<n) {
            parent(st+'(',n,no+1,nc,v);   
        }
        if(nc<no) {
            parent(st+')',n,no,nc+1,v);
        }
        if(nc==n) {
            if(no==nc) {
                v.push_back(st);
                return;
            }
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> v;
        parent("",n,0,0,v);
        return v;
    }
};