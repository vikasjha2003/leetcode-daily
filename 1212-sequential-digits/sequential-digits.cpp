class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string str = "123456789";
        vector<int> seq;

        for(int i = 0; i<9; i++) {
            string cur = "";
            cur.push_back(str[i]);
            for(int j = i+1; j<9; j++) {
                cur.push_back(str[j]);
                seq.push_back(stoi(cur));
            }
        }
        
        vector<int> res;

        for(int it : seq) {
            if(it >= low && it <= high) {
                res.push_back(it);
            }
        }

        sort(res.begin(),res.end());

        return res;
    }
};