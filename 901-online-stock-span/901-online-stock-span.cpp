class StockSpanner {
public:
    stack<pair<int, int>> st;
    int index;
    
    StockSpanner() {
        index = -1;
    }
    
    int next(int price) {
        // index variable stores the index of the current price
        index++;
        
        // pop the smaller elements from the stack because they will be useless
        // This is because they are smaller then the current element,
        // so the current element will serve as a 
        // nearest previous greater element for the next elements
        while(!st.empty() && st.top().second <= price)
            st.pop();
        
        
        // stack is empty, it means that we have not found previous greater elem
        // so, span will be index + 1
        // else index will be current idx - top element's index
        if(st.empty()) {
            st.push({index, price});
            return index + 1;
        }
        else {
            int topIndex = st.top().first;
            st.push({index, price});
            return index - topIndex;
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */