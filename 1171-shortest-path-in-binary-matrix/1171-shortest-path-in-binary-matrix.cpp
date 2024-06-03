class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
         int n = grid.size();

    if (grid[0][0] == 1 || grid[n-1][n-1] == 1) {
        return -1;
    }
    
    if (n == 1) {
        return grid[0][0] == 0 ? 1 : -1;
    }
    int dr[] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int dc[] = {-1, 0, 1, 1, 1, 0, -1, -1};
    

    queue<pair<int, pair<int, int>>> q;
    q.push({1, {0, 0}});  
    vector<vector<int>> visited(n, vector<int>(n, 0));
    visited[0][0] = 1;
    
    while (!q.empty()) {
        auto it = q.front();
        q.pop();
        int path_length = it.first;
        int row = it.second.first;
        int col = it.second.second;
        
        
        if (row == n - 1 && col == n - 1) {
            return path_length;
        }
        
        
        for (int i = 0; i < 8; ++i) {
            int new_row = row + dr[i];
            int new_col = col + dc[i];
            
            if (new_row >= 0 && new_row < n && new_col >= 0 && new_col < n && 
                grid[new_row][new_col] == 0 && !visited[new_row][new_col]) {
                visited[new_row][new_col] = 1;
                q.push({path_length + 1, {new_row, new_col}});
            }
        }
    }
    
    
    return -1;
    }
};