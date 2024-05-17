class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vec;
        if (numRows == 0) return vec; 
        
        vec.push_back({1});  
        if (numRows == 1) return vec; 
        
        for (int i = 1; i < numRows; i++) {
            vector<int> row = {1};  
            for (int j = 1; j < i; j++) {
                row.push_back(vec[i - 1][j - 1] + vec[i - 1][j]);  
            }
            row.push_back(1);  
            vec.push_back(row);  
        }
        return vec;
    }
};
