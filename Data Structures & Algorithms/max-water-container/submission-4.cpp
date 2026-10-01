class Solution {
public:
    int maxArea(std::vector<int>& heights) {
        auto l = 0;
        auto r = heights.size() - 1;
        auto max_area = 0;
        while (l < r) {
            auto width = static_cast<int>(r) - l;
            auto height = std::min(heights[l], heights[r]);

            max_area = std::max(max_area, width * height);

            if (heights[l] < heights[r]) {
                ++l;
            } else {
                --r;
            }
        }

        return max_area;
    }
};
