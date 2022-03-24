class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
     
        // sort
        sort(people.begin(), people.end());
        
        int i = 0, j = people.size() - 1;
        int boats = 0;
        
        while(i <= j) {
            if(people[i] + people[j] <= limit) {
                i++;
                j--;
            }
            else {
                j--;
            }
            boats++;
        }
        
        return boats;
    }
};