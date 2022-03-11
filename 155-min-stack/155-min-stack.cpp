class MinStack {
public:
    stack<int> st;
    stack<int> minSt;
    
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()) {
            st.push(val);
            minSt.push(val);
        }
        else {
            st.push(val);
            int currMin = minSt.top();
            if(currMin < val)
                minSt.push(currMin);
            else
                minSt.push(val);
        }
    }
    
    void pop() {
        if(!st.empty()) {
            st.pop();
            minSt.pop();
        }
    }
    
    int top() {
        if(!st.empty())
            return st.top();
        else
            return -1;
    }
    
    int getMin() {
        if(!minSt.empty())
            return minSt.top();
        else
            return -1;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */