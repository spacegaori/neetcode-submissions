class Solution {
public:

    std::string encode(std::vector<std::string>& strs) {
        std::string encoded_str{};
        for (const std::string& str : strs) {
            encoded_str += std::to_string(str.size()) + "#" + str;
        }

        return encoded_str;
    }

    std::vector<std::string> decode(const std::string& s) {
        std::vector<std::string> decoded_strs{};
        std::size_t i = 0;
        while (i < s.size()) {
            std::size_t j = i;
            while (j < s.size() && s[j] != '#') { ++j; }
            std::size_t len = std::stoul(s.substr(i, j - i));
            ++j;
            decoded_strs.push_back(s.substr(j, len));
            i = j + len;
        }

        return decoded_strs;
    }
};
