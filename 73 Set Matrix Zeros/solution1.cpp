class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        set<int> rows;
        set<int> cols;

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (matrix[row][col] == 0) {
                    rows.insert(row);
                    cols.insert(col);
                }
            }
        }

        for (auto &row : rows) {
            for (int col = 0; col < n; col++) {
                matrix[row][col] = 0;
            }
        }

        for (auto &col : cols) {
            for (int row = 0; row < m; row++) {
                matrix[row][col] = 0;
            }
        }

    }
};