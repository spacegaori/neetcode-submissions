class Solution {
public:
    bool isValid(std::string s) {
        std::unordered_map<char, char> brackets {
            {')', '('},
            {']', '['},
            {'}', '{'},
        };

        std::stack<char> stk{};
        for (const char c : s) {
            if (const auto it = brackets.find(c); it != brackets.end()) {
                if (stk.empty() || stk.top() != it->second) {
                    return false;
                }
                stk.pop();
                continue;
            } 
            stk.push(c);
        }

        return stk.empty();
    }
};
