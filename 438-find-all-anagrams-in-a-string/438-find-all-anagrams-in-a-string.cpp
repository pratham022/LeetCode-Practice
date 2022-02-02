class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        int n = s.length();
        int m = p.length();
        
        // arrays to store frequencies of the elements
        vector<int> sv(26, 0);
        vector<int> pv(26, 0);
        
        // final index array
        vector<int> res;
        
        // corner case
        if(m > n)
            return res;
        
        // populate the p array vector
        for(char c : p)
            pv[c-'a']++;
        
        // populate s vector initial `m` elements from string s
        int i;
        for(i=0; i<m; i++) {
            char c = s[i];
            sv[c-'a']++;
        }
        
        while(i < n) {
            // i - m will be the starting index of the string ending at i-1
            int startInd = i - m;
            
            // if frequency arrays match, push the start index into final array
            if(sv == pv) {
                res.push_back(startInd);
            }
            
            // update the frequency arrays
            char c = s[startInd];
            sv[c-'a']--;
            
            c = s[i];
            sv[c-'a']++;
            
            i++;
            
        }
        
        if(sv == pv) {
            res.push_back(n - m);
        }
        return res;
        
    }
};