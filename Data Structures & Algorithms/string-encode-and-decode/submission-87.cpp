class Solution {
public:
    // # 

    std::string encode(std::vector<std::string>& strs) {
        std::string encoded_str = "";

        for (const std::string& s : strs) {
            encoded_str += std::to_string(s.size());
            std::cout << std::to_string(s.size());
            encoded_str += '@';
            std::cout << '@';
            encoded_str += s;
            std::cout << s;
        }

        std::cout << encoded_str;
        return encoded_str;
    }

    std::vector<std::string> decode(std::string s) {
        int i = 0;
        int j = 0;

        std::vector<std::string> decoded_strs;
        while (j < s.size()) {
            while (j < s.size() && s[j] != '@') {
                j++;
            }
            // j == '@'
            int len = std::stoi(s.substr(i, j - i + 1));
            i = j + 1;

            std::string word = s.substr(i, len);

            decoded_strs.push_back(word);
            i += len;
            j = i;
        }

        return decoded_strs;
    }
};
