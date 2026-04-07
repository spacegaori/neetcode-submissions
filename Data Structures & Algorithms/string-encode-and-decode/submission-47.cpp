#include <charconv>   // std::from_chars
#include <limits>     // std::numeric_limits

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
        const std::size_t n = s.size();

        while (i < n) {
            std::size_t j = s.find('#', i);
            if (j == std::string::npos) break;

            if (j == i) { i = j + 1; continue; }
            unsigned long long len64 = 0;
            auto* first = s.data() + i;
            auto* last = s.data() + j;
            auto fc = std::from_chars(first, last, len64, 10);
            if (fc.ec != std::errc{} || fc.ptr != last) break;
            
            if (len64 > std::numeric_limits<std::size_t>::max()) break;
            std::size_t len = static_cast<std::size_t>(len64);

            std::size_t start = j + 1;
            if (start > n || len > n - start) break;
            decoded_strs.emplace_back(s, start, len);

            i = start + len;
        }

        return decoded_strs;
    }
};
