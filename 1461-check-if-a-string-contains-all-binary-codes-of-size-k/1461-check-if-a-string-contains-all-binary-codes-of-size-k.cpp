class Solution {
public:
    bool hasAllCodes(string s, int k) {
        
        int n = s.length();
        if(n < k)
            return false;
        
        set<string> pool;
        string curr = "";
        for(int i=0; i<k; i++)
            curr += s[i];
        
        int i = 0, j = k-1;
        while(j < n) {
            pool.insert(s.substr(i, k));
            i++;
            j++;
        }
        
        if(pool.size() == pow(2, k))
            return true;
        else
            return false;
        
        
    }
};