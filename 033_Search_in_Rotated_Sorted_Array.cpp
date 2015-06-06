class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, m;
        while(l <= r) {
            m = (l + r) >> 1;
            if(nums[m] == target)
                return m;
            if(nums[m] >= nums[l]) {
                if(nums[l] <= target && target <= nums[m])
                    r = m - 1;
                else
                    l = m + 1;
            } else {
                if(nums[m] < target && target <= nums[r])
                    l = m + 1;
                else
                    r = m - 1;
            }
        }
        return -1;
    }
};
