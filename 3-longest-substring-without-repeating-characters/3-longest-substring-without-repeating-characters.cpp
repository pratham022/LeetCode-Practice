class Solution {
public:
    bool isTableValid(int freq[]) {
        for(int i=0; i<256; i++) {
            if(freq[i] > 1)
                return false;
        }
        return true;
    }
    int lengthOfLongestSubstring(string s) {
        
        int n = s.length();
        int freq[256] = {0};
        
        int i = 0, j = 0;
        int ans = 0;
        
        while(j < n) {
            freq[s[j]]++;
            
            if(isTableValid(freq)) {
                ans = max(ans, j-i+1);
                j++;
            }
            else {
                while(!isTableValid(freq)) {
                    freq[s[i]]--;
                    i++;
                }
                j++;
            }
        }
        return ans;
        
    }
};