class Solution {
public:
    std::string encode(std::vector<std::string>& strs) {
        std::string encoded_str;
        for (const auto& str : strs) {
            encoded_str += std::to_string(str.size()) + "#" + str;
        }

        return encoded_str;
    }

    std::vector<std::string> decode(std::string str) {
        std::vector<std::string> decoded_strs;
        int i = 0;
        while (i < str.size()) {
            int j = i;
            while (str[j] != '#') j++;
            int length = std::stoi(str.substr(i, j - i));
            i = j + 1;
            j = i + length;

            decoded_strs.push_back(str.substr(i, length));
            i = j;
        }

        return decoded_strs;
    }
};
