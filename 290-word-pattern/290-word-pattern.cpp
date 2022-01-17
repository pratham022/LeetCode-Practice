class Solution {
public:
    vector<string> splitString(string s) {
        
        string curr = "";
        vector<string> res;
        
        for(int i=0; i<s.length(); i++) {
            if(s[i] == ' ') {
                res.push_back(curr);
                curr = "";
            }
            else
                curr += s[i];
        }
        
        if(curr.length() > 0)
            res.push_back(curr);
        return res;
    }
    bool wordPattern(string pattern, string s) {

        vector<string> words = splitString(s);
        if(words.size() != pattern.length())
            return false;
        
        // "abba"
        // "dog dog dog dog"
        // Expected output is false here...we want 1:1 mapping from both sides
        
        unordered_map<char, string> mp;
        unordered_map<string, int> assigned;
        
        for(int i=0; i<pattern.length(); i++) {
            char c = pattern[i];
            string str = words[i];
        
            
            if(mp.find(c) == mp.end()) {   
                if(assigned.find(str) == assigned.end()) {
                    // word is not yet assign...so we can map it
                    mp[c] = str;
                    assigned[str] = 1;
                }
                else {
                    // 1:1 mapping from string to char fails...
                    return false;
                }
            }
            else {
                if(mp[c] != str) {
                    // pattern and word does not match
                    return false;
                }
            }
        }
        
        // all the words mapped...so return true
        return true;
    
        
    }
};