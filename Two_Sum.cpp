#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <map>
using namespace std;

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

int main() {
    Solution ss;
    vector<int> x;
    x.push_back(3);
    x.push_back(2);
    x.push_back(4);
    vector<int> ans = ss.twoSum(x, 6);
    cout << ans[0] << ' ' << ans[1] << endl;
    return 0;
}
