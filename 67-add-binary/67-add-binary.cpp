class Solution {
public:
    int binaryAddition(int a, int b, int carry, string &s){
        int sum = a + b + carry;
        if(sum == 3){
            s.push_back('1');
            return 1;
        }
        else if(sum == 2){
            s.push_back('0');
            return 1;
        }
        else if(sum == 1){
            s.push_back('1');
            return 0;
        }
        else if(sum == 0){
             s.push_back('0');
            return 0;
        }    
        return -1;
    }
    string addBinary(string a, string b) {
        
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
    
        string res = "";
        
        int n = a.length();
        int m = b.length();
        
        int i;
        int sum = 0, carry = 0;
        for(i=0; i<min(n, m); i++) {
            carry = binaryAddition(a[i]-'0', b[i]-'0', carry, res);
        }
        
        while(i < n) {
            carry = binaryAddition(a[i]-'0', 0, carry, res);
            i++;
        }
        while(i < m) {
            carry = binaryAddition(0, b[i]-'0', carry, res);
            i++;
        }
        if(carry)
            res.push_back('1');
        
        reverse(res.begin(), res.end());
        return res;
    }
};