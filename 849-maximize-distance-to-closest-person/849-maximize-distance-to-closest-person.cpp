class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        
        int n = seats.size();
        
        vector<int> leftClosest(n, -1);
        if(seats[0] == 1)
            leftClosest[0] = 0;
        for(int i=1; i<n; i++) {
            if(seats[i] == 1)
                leftClosest[i] = i;
            else
                leftClosest[i] = leftClosest[i-1];
        }
        
        vector<int> rightClosest(n, -1);
        if(seats[n-1] == 1)
            rightClosest[n-1] = n-1;
        for(int i=n-2; i>=0; i--) {
            if(seats[i] == 1)
                rightClosest[i] = i;
            else
                rightClosest[i] = rightClosest[i+1];
        }
        
        int maxDist = INT_MIN;
        for(int i=0; i<n; i++) {
            int leftDistance = i - leftClosest[i];
            int rightDistance = rightClosest[i] - i;
            
            if(leftClosest[i] == -1)
                leftDistance = INT_MAX;
            if(rightClosest[i] == -1)
                rightDistance = INT_MAX;
            
            int dist = min(leftDistance, rightDistance);
            maxDist = max(maxDist, dist);
        }
        return maxDist;
        
    }
};