class Solution {
public:

    std::string encode(const std::vector<string>& strs) {
        std::string encoded_str{};
        for (const auto& s : strs) {
            encoded_str += std::to_string(s.length()) + "#" + s;
        }

        return encoded_str;
    }

    std::vector<std::string> decode(std::string s) {
        std::vector<std::string> decoded_strs{};
        int i = 0;
        while (i < s.length()) {
            int j = i;
            while (s[j] != '#') {
                j++;
            }
            int word_length = std::stoi(s.substr(i, j - i));
            i = j + 1;
            j += word_length;
            decoded_strs.push_back(s.substr(i, j - i + 1));

            i = j + 1;
        }

        return decoded_strs;
    }
};
