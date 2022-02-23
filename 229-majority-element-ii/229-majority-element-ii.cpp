class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 0)
            return {};
        
        int cand1 = -1, cand2 = -1, cnt1 = 0, cnt2 = 0;
        
        for(int x : nums) {
            if(x == cand1)
                cnt1++;
            else if(x == cand2)
                cnt2++;
            else if(cnt1 == 0) {
                cand1 = x;
                cnt1 = 1;
            }
            else if(cnt2 == 0) {
                cand2 = x;
                cnt2 = 1;
            }
            else {
                cnt1--;
                cnt2--;
            }
        }
        
        int actualCnt1 = 0, actualCnt2 = 0;
        for(int x : nums) {
            if(x == cand1)
                actualCnt1++;
            else if(x == cand2)
                actualCnt2++;
        }
        
        vector<int> res;
        if(actualCnt1 > n/3)
            res.push_back(cand1);
        if(actualCnt2 > n/3 && cand1 != cand2)
            res.push_back(cand2);
        
        return res;
    }
};