class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() < 2)
            return;
        int i, j;
        for (i = nums.size() - 2; i >= 0; i--)
            if (nums[i] < nums[i + 1])
                break;
        for (j = nums.size() - 1; j > i; j--)
            if (nums[i] < nums[j])
                break;
        if (i >= 0)
            swap(nums[i], nums[j]);
        reverse(nums.begin() + i + 1, nums.end());
    }
};
