class Solution {
public:
    int titleToNumber(string columnTitle) {
        
        // This question is very similar to base conversion
        //  Z          Y
        //(26^1)*Z  (26^0)*Y
        int n = columnTitle.size();
        int res = 0;
        
        int p = 0;
        for(int i=n-1; i>=0; i--) {
            
            char c = columnTitle[i];
            int cVal = c - 65 + 1;
            
            int curr = pow(26, p);
            curr = curr * cVal;
            res += curr;
            p++;
        }
        
        return res;
    }
};