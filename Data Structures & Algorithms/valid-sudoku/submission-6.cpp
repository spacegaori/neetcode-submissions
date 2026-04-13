class Solution {
public:

    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        auto seen = [](std::unordered_set<char>& bag, char value) {
            return !bag.insert(value).second;
        };
        std::array<std::unordered_set<char>, 9> cols{}; 
        std::array<std::unordered_set<char>, 9> rows{}; 
        std::array<std::unordered_set<char>, 9> boxes{}; 
        for (std::size_t c = 0; c < 9; ++c) {
            for (std::size_t r = 0; r < 9; ++r) {
                const char value = board[r][c];
                if (value == '.') continue;
                const std::size_t b = (c / 3) * 3 + r / 3;

                if (seen(cols[c], value) || seen(rows[r], value) || seen(boxes[b], value)) {
                    return false;
                }
            }
        }

        return true;
    }
};
