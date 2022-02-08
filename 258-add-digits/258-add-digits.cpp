class Solution {
public:
    int addDigits(int num) {
        
        int sum = 0;
        
        while(num > 0) {
            
            // add num % 10 into sum and reduce the number
            sum += num % 10;
            num = num / 10;
            
            // we can further reduce the intermediate sum
            // so, set number = sum and make sum = 0
            if(num == 0 && sum > 9) {
                num = sum;
                sum = 0;
            }
        }
        
        // return the sum
        return sum;
    }
};