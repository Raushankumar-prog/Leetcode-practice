class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
          ios_base::sync_with_stdio(false);
            cin.tie(NULL);

          int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        int freshOranges = 0;
        int minutes = 0;

        
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshOranges++;
                }
            }
        }

       
        if (freshOranges == 0) return 0;

      
        while (!q.empty()) {
            int size = q.size();
            bool rotted = false;

            for (int i = 0; i < size; ++i) {
                auto [x, y] = q.front();
                q.pop();

               
                for (auto [dx, dy] : directions) {
                    int nx = x + dx;
                    int ny = y + dy;

                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        freshOranges--;
                        q.push({nx, ny});
                        rotted = true;
                    }
                }
            }

            if (rotted) minutes++;
        }

       
        return freshOranges == 0 ? minutes : -1;   
    }
};