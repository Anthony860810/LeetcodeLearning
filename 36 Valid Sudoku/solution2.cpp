class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> rows(9, 0);
        vector<int> cols(9, 0);
        vector<int> square(9, 0);

        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[0].size(); col++) {
                char val = board[row][col];

                if (val == '.')
                    continue;

                int num = val - '1';
                int num_flag = 1 << num;
                int square_loc = (row / 3) * 3 + (col / 3);

                if (rows[row] & num_flag ||
                    cols[col] & num_flag ||
                    square[square_loc] & num_flag) {
                    return false;
                }

                rows[row] |= num_flag;
                cols[col] |= num_flag;
                square[square_loc] |= num_flag;
            }
        }

        return true;
    }
};
