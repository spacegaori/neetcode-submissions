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
            if (const auto it = matches.find(ch); it != matches.end()) {
                std::cout << "hopefully there's a match...\n";
                if (stk.empty()) {
                    std::cout << "the stack is empty, nothing to match :(\n";
                    return false;
                }
                if (stk.top() != it->second) {
                    std::cout << "wrong match :(\n";
                    return false;
                }
                std::cout << "correct match " << stk.top() << " found for " << it->first << '\n';
                stk.pop();
            } else {
                stk.push(ch);
                std::cout << "character pushed!\n";
            }
        }

        return stk.empty();
    }
};
