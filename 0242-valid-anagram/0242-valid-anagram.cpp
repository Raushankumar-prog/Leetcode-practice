class Solution {
public:
    bool isAnagram(string s, string t) {
         if (s.size() != t.size()) return false;
    
    unordered_map<char, int> charCount;

    for (char c : s) {
        charCount[c]++;
    }

    for (char c : t) {
        if (charCount.find(c) == charCount.end()) {
            return false;
        }
        charCount[c]--;
        if (charCount[c] == 0) {
            charCount.erase(c);
        }
    }

 
    return charCount.empty();
    }
};