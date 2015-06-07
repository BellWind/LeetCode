class Solution {
public:
    int jump(vector<int>& nums) {
        int dn = 0, up = 0, ans = 0;
        while(up < nums.size() - 1) {
            ans++;
            int tmp = up;
            for(int i = dn; i <= up; i++)
                tmp = max(tmp, i + nums[i]);
            dn++, up = tmp;
        }
        return ans;
    }
};
