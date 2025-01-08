class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        unordered_map<int, set<int>> row_cal;
        unordered_map<int, set<int>> col_cal;
        unordered_map<int, set<int>> matrix_cal;

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                char ch = board[row][col];
                if (ch != '.') {
                    int matrix_num = 3*(row/3) + col/3;

                    if (row_cal[row].find(ch) == row_cal[row].end())
                        row_cal[row].insert(ch);
                    else
                        return false;
                    if (col_cal[col].find(ch) == col_cal[col].end())
                        col_cal[col].insert(ch);
                    else
                        return false;
                    if (matrix_cal[matrix_num].find(ch) == matrix_cal[matrix_num].end())
                        matrix_cal[matrix_num].insert(ch);
                    else
                        return false;
                }
            }
        }
        return true;
    }
};