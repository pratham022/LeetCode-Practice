class Node {
public:
    int key, value;
    Node* next, *prev;
    
    Node(int k, int v) {
        key = k;
        value = v;
        next = NULL;
        prev = NULL;
    }
};
class LRUCache {
public:
    Node* head, *tail;
    int capacity, size;            // capacity: max capacity; size: current size
    unordered_map<int, Node*> mp;  // (key, node) representation
    
    LRUCache(int capacity) {
        this->capacity = capacity;
        size = 0;
        
        // head and tail point to each other
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    Node* insertIntoDLL(int key, int value) {
        
        Node* p = new Node(key, value);
        Node* temp = head->next;
        
        head->next = p;
        p->next = temp;
        temp->prev = p;
        p->prev = head;
        
        return p;
        
    }
    
    void deleteFromDLL(Node* p) {
        
        Node* prev = p->prev;
        prev->next = p->next;
        prev->next->prev = prev;
        
        delete p;
    }
    
    int get(int key) {
        
        if(mp.find(key) != mp.end()) {
            // key is present in the cache
            // get the address of the node from the map and return value
            Node* p = mp[key];
            int value = p->value;
            
            // also make p as most recently used
            deleteFromDLL(p);
            
            Node* q = insertIntoDLL(key, value);
            mp[key] = q;
            
            return q->value;
        }
        else
            return -1;
        
    }
    
    void put(int key, int value) {
        
        if(mp.find(key) != mp.end()) {
            // update the key
            // size will not play any role here, just update the previous entry
            
            // erase the old entry
            Node* p = mp[key];
            deleteFromDLL(p);
            
            // create and insert a new node and update the map
            Node* q = insertIntoDLL(key, value);
            mp[key] = q;
            
        }
        else {
            // insert the key 
            if(size + 1 <= capacity) {
                // we can insert the key without any deletion
                // so add node to DLL and to the map
                Node* p = insertIntoDLL(key, value);
                mp[key] = p;
                size++;
            }
            else {
                // we delete the Least Recently Used key from the cache
                
                Node* lruNode = tail->prev;
                // also delete it from tha map
                mp.erase(mp.find(lruNode->key));
                deleteFromDLL(lruNode);
                
                
                // Now insert the new node in DLL and map
                Node* p = insertIntoDLL(key, value);
                mp[key] = p;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */