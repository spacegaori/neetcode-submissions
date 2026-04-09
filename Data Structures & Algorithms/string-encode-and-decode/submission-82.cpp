#include <cassert>

class Solution {
public:

    std::string encode(std::vector<std::string>& strs) {
        std::string encoded_str{};
        for (const std::string& str : strs) {
            encoded_str += std::to_string(str.size()) + "#" + str;
        }

        return encoded_str;
    }

    std::vector<std::string> decode(std::string s) {
        std::vector<std::string> decoded_strs{};
        std::size_t i = 0;
        while (i < s.size()) {
            std::size_t j = i;
            while (s[j] != '#') { ++j; }
            assert(s[j] == '#');
            std::string len_str = s.substr(i, j - i);
            int len = std::stoi(len_str);
            ++j;
            std::string decoded_str = s.substr(j, len);
            decoded_strs.push_back(decoded_str);
            i = j + len;
        }

        return decoded_strs;
    }
};
