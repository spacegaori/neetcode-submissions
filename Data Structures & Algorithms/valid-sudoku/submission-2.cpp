class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        std::array<std::unordered_set<char>, 9> cols{}; 
        std::array<std::unordered_set<char>, 9> rows{}; 
        std::array<std::unordered_set<char>, 9> boxes{}; 
        for (std::size_t c = 0; c < 9; ++c) {
            for (std::size_t r = 0; r < 9; ++r) {
                char value = board[r][c];
                if (value == '.') continue;
                std::size_t b = (c / 3) * 3 + r / 3;

                if (!cols[c].insert(value).second) {
                    return false;
                }
                if (!rows[r].insert(value).second) {
                    return false;
                }
                if (!boxes[b].insert(value).second) {
                    return false;
                }
            }
        }

        return true;
    }
};
