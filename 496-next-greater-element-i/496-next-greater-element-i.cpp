class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums2.size();
        stack<int> st;
        vector<int> ngeArray(n, -1);
        
        for(int i=n-1; i>=0; i--) {
            int elem = nums2[i];
            if(st.empty())
                st.push(elem);
            else {
                while(!st.empty() && elem > st.top())
                    st.pop();
                if(!st.empty())
                    ngeArray[i] = st.top();
                st.push(elem);
                    
            }
        }
        
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++) {
            mp[nums2[i]] = ngeArray[i];
        }
        
        vector<int> res;
        
        for(int i=0; i<nums1.size(); i++) {
            res.push_back(mp[nums1[i]]);
        }
        return res;
    }
};