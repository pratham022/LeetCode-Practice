class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;
        
        for(char c : s) {
            if(c == '(' || c == '{' || c == '[')
                st.push(c);
            else {
                if(st.empty())
                    return false;
                else {
                    char tops = st.top();
                    st.pop();
                    
                    if(tops == '{' && c == '}') {}
                    else if(tops == '(' && c == ')') {}
                    else if(tops == '[' && c == ']') {}
                    else {
                        return false;
                    }
                }
            }
        }
        if(st.empty())
            return true;
        else
            return false;
        
    }
};