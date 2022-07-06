class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> mp;
        
        for(char c : s)
            mp[c]++;
        
        int len = 0;
        bool oddFreqChar = false;
        for(auto x : mp) {
            int freq = x.second;
            len += freq / 2;
            if(freq % 2 != 0)
                oddFreqChar = true;
        }
        
        len *= 2;
        if(oddFreqChar)
            len++;
        return len;
    }
};