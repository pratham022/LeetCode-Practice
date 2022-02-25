class Solution {
public:
    vector<string> splitStringIntoArr(string s) {
        
        vector<string> arr;
        string curr = "";
        
        for(int i=0; i<s.length(); i++) {
            if(s[i] == '.') {
                arr.push_back(curr);
                curr = "";
            }
            else {
                curr += s[i];
            }
        }
        arr.push_back(curr);
        return arr;
        
    }
    int compareVersion(string version1, string version2) {
        
        vector<string> a1 = splitStringIntoArr(version1);
        vector<string> a2 = splitStringIntoArr(version2);
        
        int n = a1.size();
        int m = a2.size();
        
        int i;
        for(i=0; i<n && i<m; i++) {
            
            int num1 = stoi(a1[i]);
            int num2 = stoi(a2[i]);
            
            if(num1 < num2)
                return -1;
            else if(num1 > num2)
                return 1;
        }
        
        while(i < n) {
            int num1 = stoi(a1[i]);
            int num2 = 0;
            if(num1 < num2)
                return -1;
            else if(num1 > num2)
                return 1;
            i++;
        }
        
        while(i < m) {
            int num1 = 0;
            int num2 = stoi(a2[i]);
            if(num1 < num2)
                return -1;
            else if(num1 > num2) 
                return 1;
            i++;
        }
        
        return 0;
        
    }
};