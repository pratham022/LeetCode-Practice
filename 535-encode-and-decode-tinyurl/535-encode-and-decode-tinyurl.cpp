class Solution {
public:

    map<string, string> codeUrl;    // [tiny URL -> long URL]
    map<string, string> urlCode;    // [long URL -> tiny URL]
    string pool = 
        "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890"; 
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
    
        // if long url is already encoded, simply return that tiny url
        if(urlCode.find(longUrl) != urlCode.end())
            return urlCode[longUrl];
        
        int n = pool.length();
        bool done = false;
        string curr = "";
        do {
            curr = "http://tinyurl/";
            for(int i=0; i<6; i++) {
                int randInd = rand() % (n + 1);
                curr += pool[randInd];
            }
            if(codeUrl.find(curr) == codeUrl.end()) {
                // this is the new code generated
                codeUrl[curr] = longUrl;
                urlCode[longUrl] = curr;
                done = true;
            }
            
        } while(done == false);
        
        return curr;
        
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return codeUrl[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));