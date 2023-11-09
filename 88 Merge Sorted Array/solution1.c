#include "stdio.h"

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int i = m-1;
    int j = n-1;
    int idx = m+n-1;
    while (i>=0 && j>=0) {
        if (nums1[i] > nums2[j]) {
            nums1[idx] = nums1[i];
            i--;
            idx--;
        } else {
            nums1[idx] = nums2[j];
            j--;
            idx--;
        }
    }
    while (j>=0) {
        nums1[idx] = nums2[j];
        j--;
        idx--;
    }
}

int main(){
    int m = 3;
    int nums1Size = 6;
    int n, nums2Size = 3;
    int nums1[6] = {1,2,3,0,0,0};
    int nums2[3] = {2,5,6};

    merge(nums1, nums1Size, m, nums2, nums2Size, n);
}
