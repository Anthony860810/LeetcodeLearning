class Solution {
private:
    int islands;
    int row_size;
    int col_size;

    void dfs(vector<vector<char>>& grid, int row, int col) {
        if (row >= row_size || col >= col_size ||
            row < 0 || col < 0 || grid[row][col] == '0')
            return;
        
        grid[row][col] = '0';
        dfs(grid, row + 1, col);
        dfs(grid, row - 1, col);
        dfs(grid, row, col + 1);
        dfs(grid, row, col - 1);
    }


public:
    int numIslands(vector<vector<char>>& grid) {
        islands = 0;
        row_size = grid.size();
        col_size = grid[0].size();
        
        for (int row = 0; row < row_size; row++) {
            for (int col = 0; col < col_size; col++) {
                if (grid[row][col] == '1') {
                    dfs(grid, row, col);
                    islands++;
                }
            }
        }

        return islands;
    }
};
