class Solution {
public:
    std::string encode(std::vector<std::string>& strs) {
        auto encoded_str{ ""s };
        for (const auto& str : strs) {
            encoded_str += std::to_string(str.size()) + "#" + str;
        }

        return encoded_str;
    }

    std::vector<std::string> decode(std::string str) {
        std::vector<std::string> decoded_strs;
        auto i{ 0 };
        while (i < str.size()) {
            auto j = i;
            while (str[j] != '#') {
                j++;
            }
            auto length = std::stoi(str.substr(i, j - i));
            i = j + 1;
            decoded_strs.push_back(str.substr(i, length));
            i += length;
        }
        return decoded_strs;
    }
};
