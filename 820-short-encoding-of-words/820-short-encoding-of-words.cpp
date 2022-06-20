class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        
        set<string> pool;
        
        for(int i=0; i<words.size(); i++)
            pool.insert(words[i]);
        
        for(int i=0; i<words.size(); i++) {
            string word = words[i];
            for(int j=1; j<word.length(); j++)
                pool.erase(word.substr(j));
        }
        
        int res = 0;
        for(string s : pool)
            res += s.length() + 1;
        
        return res;
        
    }
};