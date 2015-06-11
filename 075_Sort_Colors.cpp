class Solution {
public:
    void sortColors(vector<int>& nums) {
        int rcnt = 0, wcnt = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0)
                rcnt++;
            if(nums[i] == 1)
                wcnt++;
        }
        for(int i = 0; i < rcnt; i++)
            nums[i] = 0;
        for(int i = 0; i < wcnt; i++)
            nums[i + rcnt] = 1;
        for(int i = rcnt + wcnt; i < nums.size(); i++)
            nums[i] = 2;
    }
};
