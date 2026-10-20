class LRUCache {
private:
    class Node {
    public:
        int val;
        int key;
        Node* next;
        Node* prev;
        Node(int key,int val) {
            this->val = val;
            this->key = key;
            next = prev = nullptr;
        }
    };

    unordered_map<int,Node*> kvs;
    int sz;
    Node *head , *tail;

public:
    LRUCache(int capacity) {
        sz = capacity;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        cout<<"get"<<" ";
        if(kvs.find(key) == kvs.end()) return -1;

        Node* temp = kvs[key];
        temp->prev->next = temp->next;
        temp->next->prev = temp ->prev;
        touch(temp);

        return temp->val;
    }
    
    void put(int key, int value) {
        cout<<"put"<<" ";

        Node* temp;
        if(kvs.find(key) != kvs.end()) {
            kvs[key]->prev->next = kvs[key]->next;
            kvs[key]->next->prev = kvs[key] ->prev;
            temp = kvs[key];
            temp->val = value;
        } else {
            temp = new Node(key,value);
            kvs[key] = temp;
        }

        touch(temp);

        if (kvs.size() > sz) {
            tail->prev = tail->prev->prev;
            kvs.erase(tail->prev->next->key);
            delete tail->prev->next;
            tail->prev->next = tail;    
        }
    }

    void touch(Node* temp) {
        head->next->prev = temp;
        temp->next = head->next;
        temp->prev = head;
        head->next = temp;
    }
};