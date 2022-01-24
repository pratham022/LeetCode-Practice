class Solution {
public:
    bool check(string word) {
        
        int n = word.length();
        bool firstLetterCapital = false;
        if(word[0] >= 'A' && word[0] <= 'Z')
            firstLetterCapital = true;
        
        if(firstLetterCapital) {
            // if first letter is capital, all other letters must be capital
            // or all other letters must be small
            
            int capitalCnt = 0, smallCnt = 0;
            for(int i=1; i<n; i++) {
                if(word[i] >= 'A' && word[i] <= 'Z')
                    capitalCnt++;
                else
                    smallCnt++;
            }
            
            if(capitalCnt == 0 && smallCnt == n-1)
                return true;
            else if(smallCnt == 0 && capitalCnt == n-1)
                return true;
            else
                return false;
        }
        else {
            // all letters should be small
            int smallCnt = 0;
            for(int i=1; i<n; i++) {
                if(word[i] >= 'a' && word[i] <= 'z')
                    smallCnt++;
            }
            if(smallCnt == n-1)
                return true;
            else
                return false;
        }
    }
    bool detectCapitalUse(string word) {
        return check(word);
    }
};