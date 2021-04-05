# 46. Permutations
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
 

Example 1:

```
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
```
Example 2:
```
Input: nums = [0,1]
Output: [[0,1],[1,0]]
```
Example 3:
```
Input: nums = [1]
Output: [[1]]
```


Constraints:

* 1 <= nums.length <= 6
* -10 <= nums[i] <= 10
* All the integers of nums are unique.

## solution1
此題為很經典的DFS問題。我的想法是在進入DFS時，每輪都是最前面先固定好，接著讓後面開始兩兩互換。
用 (1,2,3,4)為例，在一開始先固定1為頭，接著進入DFS再把2固定，再來就會將3,4輪流互換，這樣就可以完成兩組輸出。
接著1仍舊固定為頭，因為後面的排列還未排完，因此接著改讓3固定為頭，再做2,4的輪流互換，以此類推下去，即可得到下面的輸出。
```
1,2,3,4
1,2,4,3
1,3,2,4
1,3,4,2
1,4,3,2
1,4,2,3
2,1,3,4
2,1,4,3
2,3,1,4
2,3,4,1
2,4,3,1
2,4,1,3
3,2,1,4
3,2,4,1
3,1,2,4
3,1,4,2
3,4,1,2
3,4,2,1
4,2,3,1
4,2,1,3
4,3,2,1
4,3,1,2
4,1,3,2
4,1,2,3
```