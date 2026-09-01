class Solution {
public:

    bool isValid(const std::string& s) {
        static const std::unordered_map<char, char> matches = {
            {'}', '{'},
            {']', '['},
            {')', '('},
        };

        if (s.length() % 2 != 0) return false;

        std::stack<char> stk{};
        for (const auto ch : s) {
            switch (ch) {
                case ('('):
                    stk.push(')');
                    break;
                case ('['):
                    stk.push(']');
                    break;
                case ('{'):
                    stk.push('}');
                    break;
                default:
                    if (stk.empty() || stk.top() != ch) {
                        return false;
                    }
                    stk.pop();
                    break;
            }
        }

        return stk.empty();
    }
};
