class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int tot = nums1.size() + nums2.size();
        int m1, m2;
        m1 = findKth(nums1, 0, nums2, 0, tot / 2 + 1);
        if(tot % 2 == 0)
            m2 = findKth(nums1, 0, nums2, 0, tot / 2);
        else
            m2 = m1;
        return (m1 + m2) / 2.0;
    }
private:
    int findKth(vector<int>& nums1, int h1, vector<int>& nums2, int h2, int k) {
        if(nums1.size() - h1 > nums2.size() - h2)
            return findKth(nums2, h2, nums1, h1, k);
        if(h1 >= nums1.size())
            return nums2[h2 + k - 1];
        if(k == 1)
            return min(nums1[h1], nums2[h2]);
        int k1 = k / 2, k2 = nums1.size() - h1;
        int ma = min(k1, k2), mb = k - ma;
        if(nums1[h1 + ma - 1] < nums2[h2 + mb - 1])
            return findKth(nums1, h1 + ma, nums2, h2, k - ma);
        if(nums1[h1 + ma - 1] > nums2[h2 + mb - 1])
            return findKth(nums1, h1, nums2, h2 + mb, k - mb);
        return nums1[h1 + ma - 1];
    }
};
