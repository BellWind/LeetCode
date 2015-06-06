class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = (1 << 30);
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++) {
            int m = i + 1, r = nums.size() - 1;
            while(m < r) {
                while(m < r && nums[i] + nums[m] + nums[r] - target < 0) {
                    ans = getClosest(ans, nums[i] + nums[m] + nums[r], target), m++;
                }

                while(m < r && nums[i] + nums[m] + nums[r] - target > 0) {
                    ans = getClosest(ans, nums[i] + nums[m] + nums[r], target), r--;
                }
                if(m < r && nums[i] + nums[m] + nums[r] - target == 0)
                    return target;
                m++;
            }
        }
        return ans;
    }
private:
    int getClosest(int a, int b, int t) {
        return abs(a - t) < abs(b - t) ? a : b;
    }
};
