class Solution {
public:

    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        std::array<std::array<bool, 9>, 9> cols{}; 
        std::array<std::array<bool, 9>, 9> rows{}; 
        std::array<std::array<bool, 9>, 9> boxes{}; 
        for (std::size_t r = 0; r < 9; ++r) {
            for (std::size_t c = 0; c < 9; ++c) {
                const char cell = board[r][c];
                if (cell == '.') continue;
                const std::size_t digit = cell - '1';
                const std::size_t b = (c / 3) * 3 + r / 3;

                if (cols[c][digit] || rows[r][digit] || boxes[b][digit]) {
                    return false;
                }

                cols[c][digit] = true;
                rows[r][digit] = true;
                boxes[b][digit] = true;
            }
        }

        return true;
    }
};
