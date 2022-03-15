// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> res;
    void traverse(int i, int j, int n, string path, vector<vector<int>> &m) {
        if(i < 0 || j < 0 || i >= n || j >= n || m[i][j] == 0)
            return;
        
        if(i == n-1 && j == n-1) {
            res.push_back(path);
            return;
        }
        
        m[i][j] = 0;
        
        traverse(i+1, j, n, path+'D', m);
        traverse(i-1, j, n, path+'U', m);
        traverse(i, j+1, n, path+'R', m);
        traverse(i, j-1, n, path+'L', m);
        
        m[i][j] = 1;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        
        string path = "";
        traverse(0, 0, n, path, m);
        return res;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends