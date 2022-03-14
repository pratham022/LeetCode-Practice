class Solution {
public:
    bool isPalindrome(string s, int i, int j) {
        
        while(i < j) {
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    void helper(int i, string s, vector<string> &curr, vector<vector<string>> &res) {
        
        if(i == s.length()) {
            res.push_back(curr);
            return;
        }
        
        for(int j=i; j<s.length(); j++) {
            
            if(isPalindrome(s, i, j)) {
                curr.push_back(s.substr(i, j-i+1));
                helper(j+1, s, curr, res);
                curr.pop_back();
            }
            
        }
        
    }
    vector<vector<string>> partition(string s) {
       
        vector<vector<string>> res;
        
        vector<string> curr;
        helper(0, s, curr, res);
        
        return res;
        
    }
};