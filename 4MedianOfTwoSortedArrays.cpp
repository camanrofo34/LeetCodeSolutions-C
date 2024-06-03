class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        int totalSize = nums1.size() + nums2.size();
        int medianLength = (totalSize / 2) + 1;
        std::vector<int> sortedNums(medianLength);
        int iterator1 = 0, iterator2 = 0;
        
        for (int i = 0; i < medianLength; i++) {
            if (iterator1 < nums1.size() && (iterator2 >= nums2.size() || nums1[iterator1] <= nums2[iterator2])) {
                sortedNums[i] = nums1[iterator1];
                iterator1++;
            } else {
                sortedNums[i] = nums2[iterator2];
                iterator2++;
            }
        }
        
        if (totalSize % 2 == 1) {
            return sortedNums[medianLength - 1];
        } else {
            return (sortedNums[medianLength - 1] + sortedNums[medianLength - 2]) / 2.0;
        }
    }
};
