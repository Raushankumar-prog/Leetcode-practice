class Solution {
public:
    bool rotateString(string s, string goal) {
         if (s.size() != goal.size()) return false;
    
    int n = s.size();
    
   
    for (int start = 0; start < n; ++start) {
        bool match = true;
        for (int i = 0; i < n; ++i) {
            if (s[(start + i) % n] != goal[i]) {
                match = false;
                break;
            }
        }
        if (match) return true;
    }
    
    return false;
    }
};