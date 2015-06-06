class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> h(n + 2, 0);
        h[0] = h[n + 1] = 0;
        for(int i = 1; i <= height.size(); i++)
            h[i] = max(h[i - 1], height[i - 1]);
        int ans = 0;
        for(int i = n; i >= 1; i--) {
            ans += max(0, min(h[i - 1], h[i + 1]) - height[i - 1]);
            h[i] = max(h[i + 1], height[i - 1]);
        }
        return ans;
    }
};
