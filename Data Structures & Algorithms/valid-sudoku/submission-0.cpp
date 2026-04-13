class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        std::array<std::unordered_set<int>, 9> cols{}; 
        std::array<std::unordered_set<int>, 9> rows{}; 
        std::array<std::unordered_set<int>, 9> boxs{}; 
        for (std::size_t c = 0; c < 9; ++c) {
            for (std::size_t r = 0; r < 9; ++r) {
                if (board[r][c] != '.') {
                    if (!cols[c].insert(board[r][c] - 'a').second) {
                        return false;
                    }
                    if (!rows[r].insert(board[r][c] - 'a').second) {
                        return false;
                    }
                    if (!boxs[(c / 3) * 3 + (r / 3)].insert(board[r][c] - 'a').second) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};
