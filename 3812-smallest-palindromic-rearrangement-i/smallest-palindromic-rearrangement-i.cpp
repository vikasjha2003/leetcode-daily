class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        vector<int> arr (26,0);

        for(char c : s) {
            arr[c - 'a']++;
        }

        string res = "";
        int idx = -1;
        for (int i = 0; i<26; i++) {
            if(arr[i] % 2 == 1) {
                idx = i;
            } 
            res += string (arr[i]/2 , char(i + 'a'));
        }

        string temp = res;

        if(idx != -1) {
            res.push_back(idx + 'a');
        }

        reverse(temp.begin(),temp.end());

        res += temp;

        return res;
    }
};