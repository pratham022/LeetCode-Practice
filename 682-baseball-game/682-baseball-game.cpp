class Solution {
public:
    void printStack(stack<int> st) {
        while(!st.empty()) {
            cout<<st.top()<<" ";
            st.pop();
        }
        cout<<'\n';
    }
    int calPoints(vector<string>& ops) {
        
        stack<int> record;
        int sum = 0;
        int n = ops.size();
        
        for(int i=0; i<n; i++) {
            if(ops[i] == "+") {
                int a = record.top();
                record.pop();
                int b = record.top();
                record.pop();
                
                int c = a + b;
                
                record.push(b);
                record.push(a);
                record.push(c);
                
                sum += c;
            }
            else if(ops[i] == "D") {
                int a = record.top();
                record.push(2*a);
                
                sum += 2*a;
            }
            else if(ops[i] == "C") {
                int a = record.top();
                record.pop();
                
                sum -= a;
            }
            else {
                record.push(stoi(ops[i]));
                
                sum += record.top();
            }
        }
        
        return sum;
    }
};