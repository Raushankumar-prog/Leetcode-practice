#include <vector>
using namespace std;

class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& board, int delrow[], int delcol[]) {
        vis[row][col] = 1;
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < 4; i++) {
            int nrow = delrow[i] + row;
            int ncol = delcol[i] + col;
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && board[nrow][ncol] == 'O') {
                dfs(nrow, ncol, vis, board, delrow, delcol);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
          ios_base::sync_with_stdio(false);
            cin.tie(NULL);

        int rows = board.size();
        int cols = board[0].size();
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        vector<vector<int>> vis(rows, vector<int>(cols, 0));

        
        for (int i = 0; i < cols; i++) {
            if (board[0][i] == 'O' && !vis[0][i]) {
                dfs(0, i, vis, board, delrow, delcol);
            }
        }

        
        for (int i = 0; i < cols; i++) {
            if (board[rows - 1][i] == 'O' && !vis[rows - 1][i]) {
                dfs(rows - 1, i, vis, board, delrow, delcol);
            }
        }

        
        for (int i = 0; i < rows; i++) {
            if (board[i][0] == 'O' && !vis[i][0]) {
                dfs(i, 0, vis, board, delrow, delcol);
            }
        }

        
        for (int i = 0; i < rows; i++) {
            if (board[i][cols - 1] == 'O' && !vis[i][cols - 1]) {
                dfs(i, cols - 1, vis, board, delrow, delcol);
            }
        }

    
   
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'O' && !vis[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};