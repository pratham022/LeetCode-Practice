class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        vector<int> secretFreq(10, 0);
        vector<int> guessFreq(10, 0);
        
        
        for(int i=0; i<secret.length(); i++) {
            if(secret[i] == guess[i])
                bulls++;
            else {
                secretFreq[secret[i] - '0']++;
                guessFreq[guess[i] - '0']++;
            }
        }
        
        int cows = 0;
        for(int i=0; i<10; i++) {
            cows += min(secretFreq[i], guessFreq[i]);
        }
        
        string res = "";
        res += to_string(bulls) + "A" + to_string(cows) + "B";
        return res;
        
    }
};