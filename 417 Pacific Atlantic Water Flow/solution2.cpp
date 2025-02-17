class Solution {
private:
    vector<vector<int>> directions = {{1, 0}, {-1, 0},
                                      {0, 1}, {0, -1}};
    
    void bfs(vector<vector<bool>>& ocean, queue<pair<int, int>> &ocean_queue, vector<vector<int>>& heights) {
        while (!ocean_queue.empty()) {
            pair<int, int> coordinate = ocean_queue.front();
            int r = coordinate.first;
            int c = coordinate.second;

            ocean_queue.pop();

            ocean[r][c] = true;

            for (auto dir: directions) {
                int row = r + dir[0];
                int col = c + dir[1];
                
                if (row >= 0 && col >= 0 && row < heights.size() &&
                    col < heights[0].size() && !ocean[row][col] &&
                    heights[row][col] >= heights[r][c])
                    ocean_queue.push({row, col});
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        
        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));
        vector<vector<int>> ans;

        queue<pair<int, int>> pacific_queue, atlantic_queue;

        for (int col = 0; col < cols; col++) {
            pacific_queue.push({0, col});
            atlantic_queue.push({rows - 1, col});
        }

        for (int row = 0; row < rows; row++) {
            pacific_queue.push({row, 0});
            atlantic_queue.push({row, cols - 1});
        }

        bfs(pacific, pacific_queue, heights);
        bfs(atlantic, atlantic_queue, heights);

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (pacific[row][col] && atlantic[row][col])
                    ans.push_back({row, col});
            }
        }

        return ans;
    }
};
