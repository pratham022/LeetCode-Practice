class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.length();
        int m = t.length();
        if(n != m)
            return false;
        
        map<char, char> mp;
        set<char> taken;
        for(int i=0; i<n; i++) {
            if(mp.find(s[i]) != mp.end()) {
                if(mp[s[i]] != t[i])
                    return false;
            }
            else {
                if(taken.find(t[i]) == taken.end()) {
                    mp[s[i]] = t[i];
                    taken.insert(t[i]);
                }
                else
                    return false;
            }
        }
        return true;
    }
};