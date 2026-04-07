class Solution {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string result = "";

        for (auto& str : strs) {
            result += std::to_string(str.length()) + '%' + str;
        }
        
        return result;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> result;

        int i = 0;
        while (i < s.size()) {
            int j = i;
            while (s[j] != '%') { ++j; }
            int length = stoi(s.substr(i, j - i));
            result.push_back(s.substr(j + 1, length));

            i = j + 1 + length;
        }
        
        return result;
    }
};
