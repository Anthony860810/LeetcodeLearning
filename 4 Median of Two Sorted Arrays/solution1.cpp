class Solution {
    public:
        double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
            int m = nums1.size();
            int n = nums2.size();
            int total_len = m + n;
    
            if (total_len % 2 == 1) {
                return findKthElement(nums1, 0, nums2, 0, total_len / 2 + 1);
            } else {
                int mid1 = findKthElement(nums1, 0, nums2, 0, total_len / 2);
                int mid2 = findKthElement(nums1, 0, nums2, 0, total_len / 2 + 1);
                return (mid1 + mid2) / 2.0;
            }
        }
        
    private:
        int findKthElement(const std::vector<int>& nums1, int start1, 
                           const std::vector<int>& nums2, int start2, int k) {
            int m = nums1.size() - start1;
            int n = nums2.size() - start2;
    
            // 確保 nums1 是較短的數組
            if (m > n) {
                return findKthElement(nums2, start2, nums1, start1, k);
            }
    
            // 邊界條件1: 如果 nums1 為空，答案就在 nums2 中
            if (m == 0) {
                return nums2[start2 + k - 1];
            }
    
            // 邊界條件2: 如果 k 為 1，答案就是兩個數組的第一個元素的最小值
            if (k == 1) {
                return std::min(nums1[start1], nums2[start2]);
            }
    
            // 遞迴的分割點
            int p1 = std::min(k / 2, m);
            int p2 = k - p1;
    
            // 比較兩個分割點的元素，來決定排除哪一部分
            if (nums1[start1 + p1 - 1] < nums2[start2 + p2 - 1]) {
                // 排除 nums1 的前 p1 個元素，同時更新 start1 和 k
                return findKthElement(nums1, start1 + p1, nums2, start2, k - p1);
            } else if (nums1[start1 + p1 - 1] > nums2[start2 + p2 - 1]) {
                // 排除 nums2 的前 p2 個元素，同時更新 start2 和 k
                return findKthElement(nums1, start1, nums2, start2 + p2, k - p2);
            } else {
                // 如果兩個分割點的元素相等，那麼答案就是它們
                return nums1[start1 + p1 - 1];
            }
        }
    };