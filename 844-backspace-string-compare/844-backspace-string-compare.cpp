class Solution {
public:
    string processString(string s) {
        stack<char> st;
        for(char c : s) {
            if(c == '#') {
                if(!st.empty())
                    st.pop();
            }
            else
                st.push(c);
        }
        
        string res = "";
        while(!st.empty()) {
            res += st.top();
            st.pop();
        }
        return res;
    }
    bool backspaceCompare(string s, string t) {
        string s1 = processString(s);
        string s2 = processString(t);
        
        return s1 == s2;
    }
};