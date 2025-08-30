class Solution {
public:
    bool isValidBox(vector<vector<char>>& board, int startRow, int startCol) {
    unordered_set<char> seen;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            char num = board[startRow + i][startCol + j];
            if (num == '.') continue;
            if (seen.count(num)) return false;
            seen.insert(num);
        }
    }
    return true;
}

    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            unordered_map<int, int> map1;
            for (int j = 0; j < 9; j++) {
                char num = board[i][j];
                if (num == '.') continue;
                int k = (int)num;

                if (map1.find(k) != map1.end()) 
                    return false;
                else
                    map1[k] = 1;
            }
        }

        for (int i = 0; i < 9; i++) {
            unordered_map<int, int> map2; 
            for (int j = 0; j < 9; j++) {
                char num = board[j][i];
                if (num == '.') continue;
                int k = (int)num;

                if (map2.find(k) != map2.end()) 
                    return false;
                else
                    map2[k] = 1;
            }
        }
        if(!isValidBox(board,0,0) || !isValidBox(board,0,3) || !isValidBox(board,0,6) || !isValidBox(board,3,0) || !isValidBox(board,3,3) || !isValidBox(board,3,6) || !isValidBox(board,6,0) || !isValidBox(board,6,3) || !isValidBox(board,6,6))
        {
            return false;
        }
        return true;
    }
};
