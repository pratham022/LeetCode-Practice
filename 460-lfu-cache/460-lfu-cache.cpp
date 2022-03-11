class Node {
public:
    int key, value, cnt;
    Node* next, *prev;
    
    Node(int k, int v) {
        key = k;
        value = v;
        cnt = 1;
        next = NULL;
        prev = NULL;
    }
};

class List {
public:
    int size;
    Node* head, *tail;
    
    List() {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    
    void insertIntoDLL(Node* p) {
        Node* temp = head->next;
        
        p->next = temp;
        p->prev = head;
        head->next = p;
        temp->prev = p;
        size++;
    }
    
    void deleteFromDLL(Node* p) {
        Node* prev = p->prev;
        prev->next = p->next;
        p->next->prev = prev;
        
        size--;
    }
};
class LFUCache {
public:
    map<int, Node*> keyNode;
    map<int, List*> freqList;
    int maxSizeCache;
    int minFreq;
    int currSize;
    
    LFUCache(int capacity) {
        maxSizeCache = capacity;
        minFreq = 0;
        currSize = 0;
    }
    
    void updateFreqListMap(Node* p) {
        // erase from map
        keyNode.erase(keyNode.find(p->key));
        
        // delete the node from earlier frequency list
        freqList[p->cnt]->deleteFromDLL(p);
        
        // if the current min freq list is totally empty, update the minFrequency
        if(p->cnt == minFreq && freqList[p->cnt]->size == 0) {
            minFreq++;
        }
        
        List* nextHigherFreqList = new List();
        // search for this higher frequency list' head address in freqList map
        if(freqList.find(p->cnt + 1) != freqList.end()) {
            nextHigherFreqList = freqList[p->cnt + 1];
        }
        // increment the freq / cnt of current node
        p->cnt += 1;
        
        // insert p into next higher freq list
        nextHigherFreqList->insertIntoDLL(p);
        
        // update the freqList map to this new list
        freqList[p->cnt] = nextHigherFreqList;
        
        // update the key, node map
        keyNode[p->key] = p;
    }
    
    int get(int key) {
        
        if(keyNode.find(key) != keyNode.end()) {
            // key exists in map
            Node* p = keyNode[key];
            int value = p->value;
            
            // update freq list map
            updateFreqListMap(p);
            return value;
        }
        else
            return -1;
    }
    
    void put(int key, int value) {
        if(maxSizeCache == 0)
            return;
        
        if(keyNode.find(key) != keyNode.end()) {
            // key is already present the cache
            // just update the value
            Node* p = keyNode[key];
            p->value = value;
            
            // update freq list
            updateFreqListMap(p);
        }
        else {
            if(currSize == maxSizeCache) {
                // get the list of the min freq
                List* list = freqList[minFreq];
                
                // now delete the LRU key from key-node map
                keyNode.erase(keyNode.find(list->tail->prev->key));
                
                // also node ha to be removed from freq list
                freqList[minFreq]->deleteFromDLL(list->tail->prev);
                
                currSize--;
            }
            // now, we are inserting the current element
            currSize++;
            
            // set the minFreq again to 1
            minFreq = 1;
            
            // get the list 
            List* listFreq = new List();
            if(freqList.find(minFreq) != freqList.end())
                listFreq = freqList[minFreq];
            
            // create the new node
            Node* p = new Node(key, value);
            
            // insert node into list
            listFreq->insertIntoDLL(p);
            
            // update key-node map
            keyNode[key] = p;
            
            // update freqList map
            freqList[minFreq] = listFreq;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */