class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        int n = mat.size();
        int m = mat[0].size();
        
        vector<pair<int, int>> soldiers(n);
        
        for(int i=0; i<n; i++) {
            int curr = 0;
            for(int j=0; j<m; j++) {
                if(mat[i][j] == 1)
                    curr++;
            }
            soldiers[i] = {curr, i};
        }
        
        sort(soldiers.begin(), soldiers.end());
        
        vector<int> weakestRows(k);
        for(int i=0; i<k; i++)
            weakestRows[i] = soldiers[i].second;
        
        return weakestRows;
    }
};