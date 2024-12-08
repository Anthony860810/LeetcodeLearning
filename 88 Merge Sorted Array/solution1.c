#include "stdio.h"

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int tail = m + n - 1;
        int nums1_tail = m - 1;
        int nums2_tail = n - 1;
        
        if (m == 0) {
            nums1 = nums2;
            return;
        } else if (n == 0) {
            return;
        }
        
        while(tail >= 0 && nums1_tail >= 0 && nums2_tail >= 0) {
            if (nums1[nums1_tail] >= nums2[nums2_tail]) {
                nums1[tail] = nums1[nums1_tail];
                nums1_tail--;
            } else {
                nums1[tail] = nums2[nums2_tail];
                nums2_tail--;
            }
            tail--;
        }
        if (nums1_tail >= 0) {
            for (int idx=nums1_tail; idx>=0; idx--) {
                nums1[tail] = nums1[idx];
                tail--;

            }
        } else if (nums2_tail >= 0) {
            for (int idx=nums2_tail; idx>=0; idx--) {
                nums1[tail] = nums2[idx];
                tail--;
            }
        }
        
    }
};

int main(){
    int m = 3;
    int nums1Size = 6;
    int n, nums2Size = 3;
    int nums1[6] = {1,2,3,0,0,0};
    int nums2[3] = {2,5,6};

    merge(nums1, nums1Size, m, nums2, nums2Size, n);
}
