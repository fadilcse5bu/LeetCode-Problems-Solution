class Solution {
public:
    vector<vector<string>> placements;
    bool canPlace(vector<string>& board, int n, int row, int col) {
        for(int i = 0; i < n; i++) {
            if(board[row][i] == 'Q' || board[i][col] == 'Q') return false;
        }
        for(int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if(board[i][j] == 'Q') return false;
        }
        for(int i = row, j = col; i >= 0 && j < n; i--, j++) {
            if(board[i][j] == 'Q') return false;
        }
        return true;
    }
    bool allDistinctSolution(vector<string> board, int n, int row) {
        if(row >= n) {
            placements.push_back(board);
            return false;
        }
        for(int col = 0; col < n; col++) {
            if(canPlace(board, n, row, col)) {
                board[row][col] = 'Q';
                if(allDistinctSolution(board, n, row + 1)) {
                    return true;
                }
                board[row][col] = '.';
            }
        }
        return false;
    }    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board;
        for(int i = 0; i < n; i++) {
            string str;
            for(int j = 0; j < n; j++) {
                str.push_back('.');
            }
            board.push_back(str);
        }
        allDistinctSolution(board, n, 0);
        
        return placements;
    }
};
