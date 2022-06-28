class Solution {
public:
    int minDeletions(string s) {
        map<char, int> freq;
        int n = s.length();
        
        for(int i=0; i<n; i++)
            freq[s[i]]++;
        
        vector<int> freqArr;
        for(auto x : freq)
            freqArr.push_back(x.second);
        
        set<int> pool;
        int cnt = 0;
        
        for(int i=0; i<freqArr.size(); i++) {
            if(pool.find(freqArr[i]) == pool.end())
                pool.insert(freqArr[i]);
            else {
                while(freqArr[i] > 0) {
                    freqArr[i]--;
                    cnt++;
                    if(pool.find(freqArr[i]) == pool.end()) {
                        pool.insert(freqArr[i]);
                        break;
                    }
                }
            }
        }
        
        return cnt;
        
    }
};