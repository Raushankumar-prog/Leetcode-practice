class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
      if (strs.empty()) return "";
    
    queue<char> q;
    int minLength = INT_MAX;

   
    for (auto str : strs) {
        if (str.size() < minLength) {
            minLength = str.size();
        }
    }

    for (int i = 0; i < minLength; ++i) {
        char currentChar = strs[0][i];
        bool allMatch = true;
        
        for (int j = 1; j < strs.size(); ++j) {
            if (strs[j][i] != currentChar) {
                allMatch = false;
                break;
            }
        }
        
        if (allMatch) {
            q.push(currentChar);
        } else {
            break;
        }
    }
    

    string commonPrefix = "";
    while (!q.empty()) {
        commonPrefix += q.front();
        q.pop();
    }
    
    return commonPrefix;
    }
};