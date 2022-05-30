class Solution {
public:
    int maxProduct(vector<string>& words) {
        
        int n = words.size();
        vector<vector<int>> arr(n, vector<int> (26, 0));
        
        for(int i=0; i<n; i++) {
            string s = words[i];
            for(int j=0; j<s.length(); j++) {
                arr[i][words[i][j]-'a']++;
            }
        }
        
        int ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                bool common = false;
                for(int k=0; k<26; k++) {
                    if(arr[i][k] > 0 && arr[j][k] > 0) {
                        common = true;
                        break;
                    }
                }
                if(!common) {
                    int cur=words[i].size()*words[j].size();
                    ans=max(ans,cur);

                }
            }
        }
        
        return ans;
        
    }
};