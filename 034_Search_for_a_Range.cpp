class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int l, r;
        l = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if(nums[l] != target) {
            return vector<int>({-1, -1});
        }
        ans.push_back(l);
        r = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        ans.push_back(r - 1);
        return ans;
    }
};
