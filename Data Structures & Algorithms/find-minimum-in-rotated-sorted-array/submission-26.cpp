class Solution {
public:
    int findMin(std::vector<int> &nums) {
        int l = 0;
        int r = nums.size() - 1;

        // find pivot
        if (nums[l] < nums[r]) {
            return nums[l];
        }

        while (l < r) {
            int m = l + (r - l) / 2;
            // middle is within upper bound 
            if (nums[m] < nums[r]) {
                r = m;
            } else {
                l = m + 1;
            }
        }

        return nums[l];
    }
};
