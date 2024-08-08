class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";

        int start = 0, maxLength = 1;

        
        auto isPalindrome = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
            }
            return right - left - 1; // Length of the palindrome
        };

        
        for (int i = 0; i < n; ++i) {
            
            int len1 = isPalindrome(i, i);
            if (len1 > maxLength) {
                maxLength = len1;
                start = i - (len1 - 1) / 2;
            }

          
            int len2 = isPalindrome(i, i + 1);
            if (len2 > maxLength) {
                maxLength = len2;
                start = i - (len2 - 1) / 2;
            }
        }

        return s.substr(start, maxLength);
    }
};
