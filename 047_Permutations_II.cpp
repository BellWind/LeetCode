class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp(nums);
        do {
            nextPermutation(tmp);
            ans.push_back(tmp);
        }while(!isSame(tmp, nums));
        return ans;
    }
private:
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
    bool isSame(const vector<int>& x, const vector<int>& y) {
        for(int i = 0; i < x.size(); i++) {
            if(x[i] != y[i])
                return false;
        }
        return true;
    }
};
