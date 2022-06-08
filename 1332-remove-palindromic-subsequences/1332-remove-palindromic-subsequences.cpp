class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        while(i < j) {
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int removePalindromeSub(string s) {
        if(isPalindrome(s))
            return 1;
        else
            return 2;
    }
};