class Solution {
public:
    bool isvalid(vector<vector<char>>& board,int row,int col,char k){
        int n=board.size();
        for(int i=0;i<n;i++){
            if(board[row][i]==k)
                return false;
            if(board[i][col]==k)
                return false;
            if(board[3*(row/3)+i/3][3 *(col/3)+i%3] == k)
                return false;
        }
        return true;
    }
    bool solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '.') {
                    for (char c = '1'; c <= '9'; c++) {
                        if (isvalid(board, i, j, c)) {
                            board[i][j] = c;
                            if (solveSudoku(board))
                                return true;
                            
                            board[i][j] = '.';
                        }
                }
                return false;
                }
            }
        }
        return true;

    }
};