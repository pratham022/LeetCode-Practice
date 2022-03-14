class Solution {
public:
    string next_permutation(string s) {
        
        int n = s.length();
        bool flag = false;
        
        for(int i=n-1; i>0; i--) {
            
            if(s[i] > s[i-1]) {
                i--;
                flag = true;
                int diff;
                int ansDiff;
                int ind = i;
                
                for(int j=i+1; j<n; j++) {
                    if(s[j] > s[i]) {
                        diff = s[j] - s[i];
                        if(diff < ansDiff) {
                            ansDiff = diff;
                            ind = j;
                        }
                    }
                }
                swap(s[i], s[ind]);
                reverse(s.begin()+i+1, s.end());
                break;
            }
        }
        if(flag == false)
            reverse(s.begin(), s.end());
        
        return s;
        
    }
    string getPermutation(int n, int k) {
        
        string res = "";
        for(int i=1; i<=n; i++) {
            res += to_string(i);
        }
        for(int i=1; i<k; i++) {
            res = next_permutation(res);
        }
        return res;
    }
};