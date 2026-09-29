class Solution {
public:

    std::string encode(std::vector<std::string>& strs) {
        // 11@Caterpillar5@Swarm

        auto encoded_str = ""s;
        for (const auto str : strs) {
            encoded_str += std::to_string(str.size()) + "@" + str;
        }

        std::cout << encoded_str << '\n';
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
            std::cout << "(i, j - i - 1) = (" << i << ", " << j - i << ")\n";
            auto strlen_str = s.substr(i, j - i);
            auto strlen = std::stoi(strlen_str);
            i = j + 1; // skip over '@'
            auto str = s.substr(i, strlen);
            decoded_strs.emplace_back(str);
            i += strlen;
        }
        
        return decoded_strs;
    }
};
