class Solution {
public:
    vector< vector<int> > threeSum(vector<int>& nums) {
        vector< vector<int> > ans(NULL);
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) {
            int m = i + 1, r = nums.size() - 1;
            while(m < r) {
                while(m < r && nums[i] + nums[m] + nums[r] < 0) m++;
                while(m < r && nums[i] + nums[m] + nums[r] > 0) r--;
                if(m < r && nums[i] + nums[m] + nums[r] == 0) {
                    ans.push_back(vector<int>({nums[i], nums[m], nums[r]}));
                    while(m < r && nums[m] == nums[m + 1]) m++;
                    m++;
                    while(m < r && nums[r] == nums[r - 1]) r--;
                }
            }
            while(i < nums.size() && nums[i] == nums[i + 1]) i++;
        }
        return ans;
    }
};
