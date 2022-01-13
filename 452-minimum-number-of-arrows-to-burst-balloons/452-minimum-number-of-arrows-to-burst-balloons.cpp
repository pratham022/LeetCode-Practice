class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int count = 1;
        int prevEnd = INT_MAX;
        
        for(auto v : points) {
            if(v[0] > prevEnd) {
                prevEnd = v[1];
                count++;
            }
            else {
                prevEnd = min(prevEnd, v[1]);
            }
        }
        return count;
    }
};