class Solution {
public:
    bool isValid(vector<vector<char>>& board, char val, int row, int col) {
        for(int i = 0; i < 9; i++) {
            if(board[row][i] == val) return false;
            if(board[i][col] == val) return false;
        }
        int r = row - (row % 3), c = col - (col % 3);
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(board[r + i][c + j] == val) return false;
            }
        }
        return true;
    }
    
    bool solveBoard(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') {
                    for(char ch = '1'; ch <= '9'; ch++) {
                        if(isValid(board, ch, i, j)) {
                            board[i][j] = ch;
                            bool r = solveBoard(board);
                            if(r == true) {
                                return true;
                            }
                            else {
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solveBoard(board);
    }
};
