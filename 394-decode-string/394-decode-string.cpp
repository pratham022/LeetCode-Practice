class Solution {
public:
    string decodeString(string s) {
        int n = s.length();
        
        stack<int> numSt;
        stack<char> st;
        
        string num = "";
        for(char c : s) {
            if(c >= '0' && c <= '9') {
                num += c;
            }
            else {
                if(c == '[') {
                    st.push(c);
                    numSt.push(stoi(num));
                    num = "";
                }
                else if(c >= 'a' && c <= 'z')
                    st.push(c);
                else {
                    // closing bracket
                    string curr = "";
                    while(!st.empty() && st.top() != '[') {
                        curr += st.top();
                        st.pop();
                    }
                    st.pop();
                    
                    reverse(curr.begin(), curr.end());
                    string res = "";
                    for(int i=0; i<numSt.top(); i++) {
                        res += curr;
                    }
                    numSt.pop();
                    for(char ch : res)
                        st.push(ch);
                }
            }
        }
        
        string decoded = "";
        while(!st.empty()) {
            decoded += st.top();
            st.pop();
        }
        
        reverse(decoded.begin(), decoded.end());
        return decoded;
    }
};