class Solution {
public:
    int maxArea(std::vector<int>& heights) {
        auto l = 0;
        auto r = static_cast<int>(heights.size()) - 1;
        auto max_area = 0;
        while (l < r) {
            auto width = r - l;
            auto height = std::min(heights[l], heights[r]);
            auto area = width * height;
            max_area = std::max(max_area, area);

            if (heights[l] < heights[r]) {
                ++l;
            } else {
                --r;
            }
        }

        return max_area;
    }
};
