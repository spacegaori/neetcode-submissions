class Solution {
public:
    int findMin(std::vector<int> &nums) {
        int res = nums[0];
        int l = 0;
        int r = static_cast<int>(nums.size()) - 1;

        while (l <= r) {
            if (nums[l] < nums[r]) {
                res = std::min(res, nums[l]);
                break;
            }

            int m = l + (r - l) / 2;
            res = std::min(res, nums[m]);
            if (nums[l] <= nums[m]) {
                l = m + 1;
            } else { // if (nums[l] > nums[m]) {
                r = m - 1;
            }
        }

        return res;
    }
};


// terminating condition:
//     nums[l]>nums[r]

// 4, 5, 6 ,7
// ^        ^
// if nums[l] < nums[l + 1]: return nums[l];

// 4, 5, 0, 1, 2, 3
// ^              ^
// l     ^       r
//       m

// 3, 4, 5, 6, 1, 2
// ^              ^
// l     ^       r
//       m