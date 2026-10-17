class Solution {
public:
    bool isValid(const std::string& s) {
        const auto print_stack = [](auto& stk){
            std::cout << "stack: [ ";
            for (const auto e : stk) {
                std::cout << e << ' ';
            }
            std::cout << '\n';
        };

        const auto matching_parentheses = std::unordered_map<char, char>{
            {')', '('},
            {']', '['},
            {'}', '{'},
        };

        auto char_stack = std::vector<char>{};
        for (const auto ch : s) {
            print_stack(char_stack);
            if (const auto it = matching_parentheses.find(ch); it != matching_parentheses.end()) {
                const auto expected = it->second;
                if (char_stack.empty()) {
                    return false;
                }
                const auto top = char_stack.back();
                if (expected != top) {
                    return false;
                }
                char_stack.pop_back();
                continue;
            }
            char_stack.push_back(ch);
        }

        if (!char_stack.empty()) {
            return false;
        }

        return true;
    }
};
