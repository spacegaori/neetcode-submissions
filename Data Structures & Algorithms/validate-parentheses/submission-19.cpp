class Solution {
public:
    const std::unordered_map<char, char> matches = {
        {'}', '{'},
        {']', '['},
        {')', '('},
    };

    bool isValid(const std::string& s) {
        std::stack<char> stk{};
        for (const auto ch : s) {
            if (const auto& it = matches.find(ch); it != matches.end()) {
                if (stk.empty()) {
                    return false;
                }
                if (stk.top() != it->second) {
                    return false;
                }
                stk.pop();
            } else {
                stk.push(ch);
            }
        }

        return stk.empty();
    }
};
