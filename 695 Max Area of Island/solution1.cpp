class Solution {

private:
    int max_area;

    void dfs(vector<vector<int>>& grid, int row, int col, int &cur_area) {
        if (row >= grid.size() || col >= grid[0].size() ||
            row < 0 || col < 0 || grid[row][col] == 0)
            return;
        
        grid[row][col] = 0;
        cur_area++;

        dfs(grid, row + 1, col, cur_area);
        dfs(grid, row - 1, col, cur_area);
        dfs(grid, row, col + 1, cur_area);
        dfs(grid, row, col - 1, cur_area);
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        max_area = 0;
        int cur_area = 0;

        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                if (grid[row][col] == 1) {
                    cur_area = 0;
                    dfs(grid, row, col, cur_area);
                }
                max_area = max(max_area, cur_area);
            }
        }

        return max_area;
    }
};
