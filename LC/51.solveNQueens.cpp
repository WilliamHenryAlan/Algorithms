class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n,string(n,'.'));
        function<void(int)> dfs = [&](int row) {
            if (row == n) {
                ans.push_back(board);
                return;
            }
            for (int column = 0;column < n;column++) {
                if (isValid(board,row,column,n)) {
                    board[row][column] = 'Q';
                    dfs(row + 1);
                    board[row][column] = '.';
                }
            }
        };
        dfs(0);
        return ans;
    }
    bool isValid(const vector<string>& board, int row, int col, int n) {
        // 检查同列是否有皇后
        for (int i = 0; i < row; ++i) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }

        // 检查左上方是否有皇后
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        // 检查右上方是否有皇后
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
};