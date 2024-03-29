class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    int topElem;
    
    MyStack() {
        topElem = -1;
    }
    
    void push(int x) {
        // O(1) push
        q1.push(x);
        topElem = x;
    }
    
    int pop() {
        
        // O(n) pop
        int elem = -1;
        while(q1.size() > 1) {
            topElem = q1.front();
            q2.push(q1.front());
            q1.pop();
        }
        elem = q1.front();
        q1.pop();
        
        // again push all elements back into q1
        while(!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
        return elem;
        
    }
    
    int top() {
        return topElem;
    }
    
    bool empty() {
        if(q1.size() == 0)
            return true;
        else
            return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */