class Solution {
public:
    int findMin(std::vector<int> &nums) {
        int l = 0;
        int r = static_cast<int>(nums.size()) - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] < nums[r]) {
                r = m;
            } else { // if (nums[l] > nums[m]) {
                l = m + 1;
            }
        }

        return nums[l];
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