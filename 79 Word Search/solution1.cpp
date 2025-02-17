class Solution {
    private:
        vector<vector<int>> directions = {{1, 0}, {-1, 0},
                                          {0, 1}, {0, -1}};
    
        bool dfs(vector<vector<char>>& board, string& word, int r, int c, int pos) {
            if (pos == word.size())
                return true;
    
            if (r < 0 || r >= board.size() || 
                c < 0 || c >= board[0].size() || 
                board[r][c] != word[pos])
                return false;
    
            char temp = board[r][c];
            board[r][c] = '#';
    
            for (auto& dir : directions) {
                int row = r + dir[0];
                int col = c + dir[1];
                if (dfs(board, word, row, col, pos + 1))
                    return true;
            }
    
            board[r][c] = temp;
            return false;
        }
    
    public:
        bool exist(vector<vector<char>>& board, string word) {
            int rows = board.size(), cols = board[0].size();
            for (int row = 0; row < rows; row++) {
                for (int col = 0; col < cols; col++) {
                    if (board[row][col] == word[0]) {
                        if (dfs(board, word, row, col, 0))
                            return true;
                    }
                }
            }
            return false;
        }
    };
    