class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        array<array<char, 9>, 9> rowSet{};
        array<array<char, 9>, 9> colSet{};
        array<array<char, 9>, 9> boxSet{};
        for (int row{}; row < board.size(); ++row) {
            for (int col{}; col < board[0].size(); ++col) {
                if (board[row][col] == '.') continue;
                int numCol{static_cast<int>((board[row][col] - '0') - 1)};
                int currBox{(row / 3) * 3 + (col / 3)};
                if (rowSet[row][numCol] || colSet[col][numCol] || boxSet[currBox][numCol]) return false;
                rowSet[row][numCol] = 1;
                colSet[col][numCol] = 1;
                boxSet[currBox][numCol] = 1;
            }
        }
        return true;
    }
};
