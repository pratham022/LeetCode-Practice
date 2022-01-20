class Solution {
public:
    bool isValid(vector<int>& piles, int h, long long k) {
        long long sum = 0;
        for(int x : piles) {
            sum += (x / k);
            if(x % k != 0)
                sum++;
        }
        
        if(sum <= h)
            return true;
        else
            return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        long long sum = 0;
        for(int x : piles)
            sum += x;
        
        long long low = 0, high = sum;
        long long mid;
        long long ans = sum;
        
        while(low <= high) {
            mid = low + (high - low) / 2;
            
            if(mid == 0)
                low = mid + 1;
            else if(isValid(piles, h, mid)) {
                ans = min(ans, mid);
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return ans;
        
    }
};