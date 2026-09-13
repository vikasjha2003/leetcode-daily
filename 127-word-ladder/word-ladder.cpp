class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord == endWord) return 0;
        int n = beginWord.size();
        
        unordered_set<string> st;
        for(auto &word : wordList) {
            st.insert(word);
        }

        if(st.find(endWord) == st.end()) return 0;
        
        queue<string> q;
        q.push(beginWord);
        string character = "abcdefghijklmnopqrstuvwxyz";
        int res = 0;

        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                string text = q.front();
                q.pop();
                if(text == endWord) return ++res;
                for(int i = 0; i<n; i++) {
                    string str = text;
                    for(char c : character) {
                        str[i] = c;
                        if(st.find(str) != st.end()) {
                            q.push(str);
                            st.erase(str);
                        }
                    }
                }
            }
            res++;
        }

        return 0;
    }
};