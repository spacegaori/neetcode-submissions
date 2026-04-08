#include <cassert> 

class Solution {
public:
    std::string encode(std::vector<std::string>& strs) {
        auto str_encoded{ ""s };
        for (const std::string& str : strs) {
            const auto len = static_cast<int>(str.size());
            str_encoded += std::to_string(len) + "#" + str;
        }

        return str_encoded;
    }

    std::vector<std::string> decode(std::string s) {
        std::vector<std::string> decoded_strs{};
        std::size_t i = 0;
        while (i < s.size()) {
            std::size_t j = i;
            while (s[j] != '#') {
                ++j;
            }
            auto len = std::stoi(s.substr(i, j - i));
            ++j;
            decoded_strs.push_back(s.substr(j, len));
            i = j + len;
        }

        return decoded_strs;
    }
};
