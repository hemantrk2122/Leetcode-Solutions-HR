class LRUCache {
public:
    class Node{
        public:
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int _key,int _val){
            key = _key;
            val = _val;
        }
    };
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    
    int cap;
    unordered_map<int,Node*>mp;
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void addNode(Node* toBeAddedNode){
        Node* temp = head->next;
        toBeAddedNode->next = temp;
        toBeAddedNode->prev = head;
        
        
        head->next = toBeAddedNode;
        temp->prev = toBeAddedNode;
        
    }
    void deleteNode(Node* toBeDeletedNode){
        Node* prevOfToBeDeletedNode = toBeDeletedNode->prev;
        Node* nextOfToBeDeletedNode = toBeDeletedNode->next;
        
        prevOfToBeDeletedNode->next = nextOfToBeDeletedNode;
        nextOfToBeDeletedNode->prev = prevOfToBeDeletedNode;
    }
    int get(int key_) {
        if (mp.find(key_) != mp.end()) {
            Node* resnode = mp[key_];
            int res = resnode->val;
            mp.erase(key_);
            deleteNode(resnode);
            addNode(resnode);
            mp[key_] = head->next;
            return res; 
        }
    
        return -1;
    }
    
    void put(int key_, int value) {
        if(mp.find(key_) != mp.end()) {
            Node* existingnode = mp[key_];
            mp.erase(key_);
            deleteNode(existingnode);
        }
        if(mp.size() == cap) {
          mp.erase(tail->prev->key);
          deleteNode(tail->prev);
        }
        
        addNode(new Node(key_, value));
        mp[key_] = head->next; 
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */