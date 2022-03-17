class Solution {
public:
    int scoreOfParentheses(string s) {
        
        stack<int> st;
        st.push(0);
        
        for(char c : s) {
            
            if(c == '(')
                st.push(0);
            else {
                
                int tops = st.top();
                st.pop();
                
                int val = 0;
                if(tops > val)
                    val = 2 * tops;
                else
                    val = 1;
                
                st.top() += val;
            }
        }
        
        return st.top();
        
    }
};