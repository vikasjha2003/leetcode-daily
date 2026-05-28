class Node {
    private:

    Node* links[26] = {nullptr};
    bool flag = false;

    public:

    bool containsKey(char c) {
        return links[c-'a'] != nullptr;
    }

    void setKey(char c) {
        links[c-'a'] = new Node();
    }

    Node* get(char c) {
        return links[c-'a'];
    }

    void setEnd() {
        flag = true;
    }

    bool getEnd() {
        return flag;
    }
};

class Trie {

private: Node* root;

public:

    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root; 

        for(int i = 0; i<word.length(); i++) {
            if(!node->containsKey(word[i])) {
                node->setKey(word[i]);
            }
            node = node->get(word[i]);
        }

        node->setEnd();
    }
    
    bool search(string word) {
        Node* node = root;

        for(int i = 0; i<word.length(); i++) {
            if(!node->containsKey(word[i])) {
                return false;
            }
            node = node->get(word[i]);
        }

        return node->getEnd();
    }
    
    bool startsWith(string prefix) {
        Node* node = root;

        for(int i = 0; i<prefix.length(); i++) {
            if(!node->containsKey(prefix[i])) {
                return false;
            }
            node = node->get(prefix[i]);
        }

        return true;
    }
};