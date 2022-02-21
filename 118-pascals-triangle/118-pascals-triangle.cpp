class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> res;
        
        vector<int> prev;
        
        for(int i=1; i<= numRows; i++) {
            
            vector<int> curr;
            if(i == 1) {
                // 1st row
                curr = {1};
            }
            else if(i == 2) {
                // 2nd row
                curr = {1, 1};  
            }
            else {
                // from 3rd row onwards
                curr.push_back(1);
                for(int j=0; j<prev.size()-1; j++) {
                    
                    int sum = prev[j] + prev[j+1];
                    curr.push_back(sum);
                }
                curr.push_back(1);
                
            }
            res.push_back(curr);
            prev = curr;
        }
        
        return res;
        
    }
};