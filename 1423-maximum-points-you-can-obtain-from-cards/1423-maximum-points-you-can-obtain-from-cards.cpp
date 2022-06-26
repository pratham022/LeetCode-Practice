class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sum = 0, ansSum = INT_MAX;
        int i = 0, j = 0;
        int len = n - k;
        
        while(j < len) {
            sum += cardPoints[j];
            j++;
        }
        ansSum = sum;
        // cout<<ansSum<<'\n';
        
        while(j < n) {
            ansSum = min(ansSum, sum);
            
            sum -= cardPoints[i];
            i++;
            sum += cardPoints[j];
            j++;
            // cout<<sum<<" "<<ansSum<<'\n';
        }
        ansSum = min(ansSum, sum);
        
        int totSum = 0;
        for(int x : cardPoints)
            totSum += x;
        
        return totSum - ansSum;
    }
};