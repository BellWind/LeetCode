class Solution {
public:
    int maxArea(vector<int> &height) {
        int i = 0, j = height.size() - 1;
        int ret = 0;

         while(i < j) {
             if(height[i] < height[j]) {
                    ret = max(ret, (j - i) * height[i]);
                    i++;
             } else {
                    ret = ret > (j - i) * height[j] ? ret : (j - i) * height[j];
                    j--;
            }
        }
        return ret;
    }
};
