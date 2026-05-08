class Solution {
public:
    template <typename ForwardIterator>
    auto lengthOfLongestSubstring(ForwardIterator first, ForwardIterator last) {
        using ValueType = typename std::iterator_traits<ForwardIterator>::value_type;
        using DifferenceType = typename std::iterator_traits<ForwardIterator>::difference_type;
    
        // Stepanov often preferred simple, efficient lookup tables for fixed alphabets
        // but would use a map for a truly generic 'ValueType'.
        std::unordered_map<ValueType, ForwardIterator> seen;
        
        DifferenceType max_len = 0;
        ForwardIterator window_start = first;
    
        for (ForwardIterator window_end = first; window_end != last; ++window_end) {
            auto it = seen.find(*window_end);
    
            // If found and within the current range [window_start, window_end)
            if (it != seen.end() && !(it->second < window_start)) {
                // Move the tail of the range to just after the repeat
                window_start = std::next(it->second);
            }
    
            seen[*window_end] = window_end;
            max_len = std::max(max_len, std::distance(window_start, std::next(window_end)));
        }
    
        return max_len;
    }

    template <typename Range>
    auto lengthOfLongestSubstring(const Range& r) {
        return lengthOfLongestSubstring(std::begin(r), std::end(r));
    }
};
