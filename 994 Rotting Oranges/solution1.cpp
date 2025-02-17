class Solution {
private:
    vector<vector<int>> directions = {{1, 0}, {-1, 0},
                                      {0, 1}, {0, -1}};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int time = 0;
        int fresh_cnt = 0;
        queue<pair<int, int>> q;

        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                if (grid[row][col] == 2)
                    q.push({row, col});    
                else if (grid[row][col] == 1)          
                    fresh_cnt++;
            }
        }
        
        while (!q.empty() && fresh_cnt > 0) {
            int q_length = q.size();

            for (int idx = 0; idx < q_length; idx++) {
                pair<int, int> coordinate = q.front();

                q.pop();

                for (auto direct: directions) {
                    int row = coordinate.first + direct[0];
                    int col = coordinate.second + direct[1];

                    if (row >= 0 && col >= 0 && row < grid.size() &&
                        col < grid[0].size() && grid[row][col] == 1) {
                        grid[row][col] = 2;
                        q.push({row, col});
                        fresh_cnt--;
                    }
                }
            }
            time++;
        }

        return fresh_cnt == 0 ? time : -1;

    }
};
