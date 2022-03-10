class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    
    MyQueue() {
        
    }
    
    void push(int x) {
        // first transfer all the contents from s1 to s2
        // then add new element to s1
        // again transfer all the content back to s1
        
        while(s1.size() > 0) {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(s2.size() > 0) {
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        if(!empty()) {
            int tops = s1.top();
            s1.pop();
            return tops;
        }
        else
            return -1;
    }
    
    int peek() {
        if(!empty())
            return s1.top();
        else
            return -1;
    }
    
    bool empty() {
        if(s1.size() == 0)
            return true;
        else
            return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */