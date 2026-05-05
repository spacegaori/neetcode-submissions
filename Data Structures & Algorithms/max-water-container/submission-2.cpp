class Solution {
public:
    int maxArea(std::vector<int>& heights) {
        // width = heights[l] - heights[r]
        // height = min(heights[l], heights[r])
        
        // starting: l = 0, r = heights.size() - 1
        // since we will be using heights and index as
        // integer for calculating area, let's make sure
        // to use int type for l and r.
        
        int n = static_cast<int>(heights.size());
        int l = 0;
        int r = n - 1;
        int max_area{};
        while (l < r) {
            int width = r - l;
            int height = 0;
            if (heights[l] > heights[r]) {
                height = heights[r];
                --r;
            } else {
                height = heights[l];
                ++l;
            }

            int area = width * height;
            max_area = std::max(max_area, area);
        }

        return max_area;
    }
};
