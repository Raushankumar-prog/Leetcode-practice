class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;

        int rows = matrix.size();
        int cols = matrix[0].size();
        
        int top = 0, left = 0, bottom = rows - 1, right = cols - 1;

        while (top <= bottom && left <= right) {
            int col = left;
            while (col <= right)
                result.push_back(matrix[top][col++]);
            top++;

            int row = top;
            while (row <= bottom)
                result.push_back(matrix[row++][right]);
            right--;
            
            if (top <= bottom) {
                col = right;
                while (col >= left)
                    result.push_back(matrix[bottom][col--]);
                bottom--;
            }

            if (left <= right) {
                row = bottom;
                while (row >= top)
                    result.push_back(matrix[row--][left]);
                left++;
            }
        }
        
        return result;
    }
};
