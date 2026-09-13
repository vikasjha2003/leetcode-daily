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
        string text = beginWord;
        int res = 0;

        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                text = q.front();
                q.pop();
                if(text == endWord) return res+1;

                for(auto it = st.begin(); it != st.end();) {
                    string word = *it;
                    int flag = 0;
                    for(int i = 0; i<n; i++) {
                        if(text[i] != word[i]) flag++;
                        if(flag == 2) break;
                    }

                    if(flag <= 1) {
                        q.push(word);
                        it = st.erase(it);
                    } else {
                        it++;
                    }
                }
            }
            res++;
        }

        return 0;
    }
};