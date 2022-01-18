class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        for(int i=0; i<flowerbed.size() && n > 0; i++) {
            
            // we can only plant at empty spots...ie where flowerbed[i] == 0
            if(flowerbed[i] == 1)
                continue;
            
            // f1 represents if we can plant a flower here checking left
            // f2 represents if we can plant a flower here checking right
            bool f1 = true, f2 = true;
            if(i-1 >= 0 && flowerbed[i-1] == 1)
                f1 = false;
            if(i+1 < flowerbed.size() && flowerbed[i+1] == 1)
                f2 = false;
            if(f1 && f2) {
                // we can plant a flower here
                flowerbed[i] = 1;
                
                // reduce the pending flower count
                n--;
            }
        }
        
        if(n == 0)
            return true;
        else
            return false;
        
    }
};