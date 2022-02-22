class Solution {
public:
    vector<vector<int>> convertStackToArr(stack<vector<int>> st) {
        
        vector<vector<int>> res;
        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        
        stack<vector<int>> st;
        
        for(int i=0; i<n; i++) {
            if(st.empty())
                st.push(intervals[i]);
            else {
                vector<int> tops = st.top();
                st.pop();
                
                vector<int> curr = intervals[i];
                
                // [start1, end1] tops
                // [start2, end2] intervals[i]
                
                if(curr[0] >= tops[0] && curr[0] <= tops[1]) {
                    // merging
                    tops[1] = max(tops[1], curr[1]);
                    st.push(tops);
                }
                else {
                    st.push(tops);
                    st.push(curr);
                }
            }
        }
        
        vector<vector<int>> res = convertStackToArr(st);
        return res;
        
    }
};