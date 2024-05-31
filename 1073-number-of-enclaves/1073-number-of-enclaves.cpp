class Solution {
public:
     void dfs(vector<vector<int>>& grid, int x, int y) {
    
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == 0) {
            return;
        }
       
        grid[x][y] = 0;
       int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
       
        for (auto dir : directions) {
            dfs(grid, x + dir[0], y + dir[1]);
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
          ios_base::sync_with_stdio(false);
            cin.tie(NULL);

          int m = grid.size(), n = grid[0].size();
        
        
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 1) {  
                dfs(grid, i, 0);
            }
            if (grid[i][n-1] == 1) {  
                dfs(grid, i, n-1);
            }
        }
        
        for (int j = 0; j < n; j++) {
            if (grid[0][j] == 1) {  
                dfs(grid, 0, j);
            }
            if (grid[m-1][j] == 1) { 
                dfs(grid, m-1, j);
            }
        }

        
        int enclave_count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    enclave_count++;
                }
            }
        }
        
        return enclave_count;
    }
};