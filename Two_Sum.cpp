class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> find_id;
        for(int i = 0; i < nums.size(); i++) {
            int tmp = target - nums[i];
            if(find_id.find(tmp) != find_id.end() && find_id[tmp] != i) {
                return vector<int>({find_id[tmp] + 1, i + 1});
            }
            find_id[nums[i]] = i;
        }
    }
};
