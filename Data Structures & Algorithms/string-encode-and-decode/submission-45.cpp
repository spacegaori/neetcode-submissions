class Solution {
public:
    std::string encode(std::vector<std::string>& strs) {
        std::string encoded_str;
        for (const auto& str : strs) {
            encoded_str += std::to_string(str.size());
            encoded_str.push_back('#');
            encoded_str += str;
        }

        return encoded_str;
    }

    std::vector<std::string> decode(std::string s) {
        std::vector<std::string> decoded_strs;
        std::size_t i = 0;
        std::size_t n = s.size();

        while (i < n) {
            std::size_t j = i;
            while (j < n && std::isdigit(static_cast<unsigned char>(s[j]))) j++;
            if (j >= n || s[j] != '#') break;

            std::size_t len = std::stoul(s.substr(i, j - i));
            j++;

            if (j + len > n) break;
            decoded_strs.emplace_back(s.substr(j, len));

            i = j + len;
        }

        return decoded_strs;
    }
};
