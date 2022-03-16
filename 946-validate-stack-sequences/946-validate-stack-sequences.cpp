class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        stack<int> st;
        
        int n = pushed.size();
        int i = 0;  // pointer for pushed array
        int j = 0;  // pointer for popped array
        
        
        while(i < n) {
            // if stack is empty, push current element into the stack
            if(st.empty()) {
                st.push(pushed[i]);
                i++;
            }    
            else {
                int tops = st.top();
                if(tops == popped[j]) {
                    while(tops == popped[j]) {
                        // we have to pop this elem
                        st.pop();
                        j++;
                    }   
                }
                else {
                    // we will push current element into the stack
                    st.push(pushed[i]);
                    i++;
                }
            }
        }
        
        // now all elements are pushed into the stack, so keep popping elements
        // until they are valid elements
        while(!st.empty() && st.top() == popped[j] && j < n) {
            st.pop();
            j++;
        }
        
        // if stack is empty, sequence of operations is valid
        if(st.empty())
            return true;
        else
            return false;
        
    }
};