class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] <= 0 || nums[i] > n) {
                nums[i] = -1;
                continue;
            }
            int t = -1, p = i;
            while(p >= 0 && p < n && nums[p] != p + 1) {
                int next = nums[p] - 1;
                nums[p] = t;
                t = next + 1;
                p = next;
            }
        }
        for(int i = 0; i < n; i++) {
            if(nums[i] != i + 1)
                return i + 1;
        }
        return n + 1;
    }
};
