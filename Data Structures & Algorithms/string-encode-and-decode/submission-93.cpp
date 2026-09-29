class Solution {
public:

    std::string encode(std::vector<std::string>& strs) {
        auto encoded_str = ""s;
        for (const auto str : strs) {
            encoded_str += std::to_string(str.size()) + "@" + str;
        }
        return encoded_str;
    }

    std::vector<std::string> decode(std::string s) {
        auto decoded_strs = std::vector<std::string>{};
        auto i = 0;
        while (i < s.size()) {
            auto j = i;
            while (s[j] != '@') {
                j++;
            }
            const auto strlen_str = s.substr(i, j - i);
            const auto strlen = std::stoi(strlen_str);
            i = j + 1; // skip over '@'
            const auto str = s.substr(i, strlen);
            decoded_strs.emplace_back(str);
            i += strlen;
        }
        
        return decoded_strs;
    }
};
