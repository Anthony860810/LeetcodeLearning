class Solution {
private:
    vector<vector<int>> directions = {{1, 0}, {-1, 0},
                                      {0, 1}, {0, -1}};
    
    void dfs(int r, int c, vector<vector<bool>>& ocean, vector<vector<int>>& heights) {
        ocean[r][c] = true;

        for (auto dir : directions) {
            int row = r + dir[0];
            int col = c + dir[1];

            if (row >= 0 && col >= 0 && row < heights.size() &&
                col < heights[0].size() && !ocean[row][col] &&
                heights[row][col] >= heights[r][c])
                dfs(row, col, ocean, heights);
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        
        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));
        vector<vector<int>> ans;

        for (int col = 0; col < cols; col++) {
            dfs(0, col, pacific, heights);
            dfs(rows - 1, col, atlantic, heights);
        }

        for (int row = 0; row < rows; row++) {
            dfs(row, 0, pacific, heights);
            dfs(row, cols - 1, atlantic, heights);
        }

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (pacific[row][col] && atlantic[row][col])
                    ans.push_back({row, col});
            }
        }

        return ans;
    }
};
