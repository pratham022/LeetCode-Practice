class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        int n = s.length();
        stack<int> st;
        
        for(int i=0; i<n; i++) {
            
            if(s[i] == '(')
                st.push(i);
            else if(s[i] == ')') {
                
                if(st.empty()) {
                // if no matching previous open parentheses found, 
                // we need to remove the index of that open parentheses from "s" 
                // so for now we are marking it with special character '#'

                    s[i] = '#';
                }
                else {
                    // if matching open parentheses found remove that from the stack
                    st.pop();
                }
            }
        }
        
        // if stack is not empty, that means it contains open parentheses 
        // indexes which don't have any matching closing parentheses
        
        while(!st.empty()) {
            s[st.top()] = '#';
            st.pop();
        }
        
        string ans = "";
        for(char c : s) {
            if(c != '#')
                ans += c;
        }
        
        return ans;

    }
};