class Solution {

private:
    int INF = INT_MAX;
    vector<vector<int>> directions = {{1, 0}, {-1, 0},
                                      {0, 1}, {0, -1}};

    int bfs(vector<vector<int>>& grid, int r, int c) {
        int steps = 0;
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

        visited[r][c] = true;
        q.push({r, c});

        while (!q.empty()) {
            int q_length = q.size();
            for (int q_idx = 0; q_idx < q_length; q_idx++) {
                pair<int, int> coordinate = q.front();

                q.pop();
                if (grid[coordinate.first][coordinate.second] == 0)
                    return steps;
                
                for (auto dir: directions) {
                    int row = coordinate.first + dir[0];
                    int col = coordinate.second + dir[1];

                    if (row >= 0 && col >= 0 && row < grid.size() &&
                        col < grid[0].size() && !visited[row][col] &&
                        grid[row][col] != -1) {
                        visited[row][col] = true;
                        q.push({row, col});
                    }
                }
            }
            steps++;
        }

        return INF;
    }


public:
    void islandsAndTreasure(vector<vector<int>>& grid) {    
        for (int row = 0; row < grid.size(); row++)
            for (int col = 0; col < grid[0].size(); col++)
                if (grid[row][col] == INF)
                    grid[row][col] = bfs(grid, row, col);

    }
};
