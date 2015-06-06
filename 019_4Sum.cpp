class Solution {
public:
    vector< vector<int> > fourSum(vector<int>& nums, int target) {
        vector< vector<int> > ans(NULL);
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                int m = j + 1, r = nums.size() - 1;
                while(m < r) {
                    while(m < r && nums[i] + nums[j] + nums[m] + nums[r] - target < 0) m++;
                    while(m < r && nums[i] + nums[j] + nums[m] + nums[r] - target > 0) r--;
                    if(m < r && nums[i] + nums[j] + nums[m] + nums[r] - target == 0) {
                        ans.push_back(vector<int>({nums[i], nums[j], nums[m], nums[r]}));
                        while(m < r && nums[m] == nums[m + 1]) m++;
                        m++;
                        while(m < r && nums[r] == nums[r - 1]) r--;
                    }
                }
                while(j < nums.size() && nums[j] == nums[j + 1]) j++;
            }
            while(i < nums.size() && nums[i] == nums[i + 1]) i++;
        }
        return ans;
    }
};
