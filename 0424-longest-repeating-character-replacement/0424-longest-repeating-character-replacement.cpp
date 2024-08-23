class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0, maxFreq = 0;
        unordered_map<char, int> mpp;
        int n = s.length();

        int maxi = 0;  
        while (r < n) {
            mpp[s[r]]++;
            maxFreq = max(maxFreq, mpp[s[r]]);

        
            if (r - l + 1 - maxFreq > k) {
                mpp[s[l]]--;
                l++;
            }

            maxi = max(maxi, r - l + 1);
            r++;
        }
        
        return maxi;
    }
};
