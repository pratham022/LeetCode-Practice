class Solution {
public:
    int countSetBits(int n) {
        int cnt = 0;
        while(n) {
            int bit = n & 1;
            if(bit == 1)
                cnt++;
            n = n >> 1;
        }
        return cnt;
    }
    vector<int> countBits(int n) {
        vector<int> res;
        
        for(int i=0; i<=n; i++) {
            int bits = countSetBits(i);
            res.push_back(bits);
        }
        return res;
    }
};