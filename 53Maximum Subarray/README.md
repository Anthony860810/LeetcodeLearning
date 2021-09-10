# 53. Maximum Subarray
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
 

Example 1:

```
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
```
Example 2:
```
Input: nums = [1]
Output: 1
```
Example 3:
```
Input: nums = [5,4,-1,7,8]
Output: 23
```


Constraints:

* 1 <= nums.length <= 3 * 104
* -105 <= nums[i] <= 105

## solution1
此題為DP，每輪都需要考慮是否要將 element 放入，若是 element 放入 subarray 可以增加 sum 則加入，而在每次加入後都要檢查是否大於maximum ，若是大於的話就要更新 maximum。