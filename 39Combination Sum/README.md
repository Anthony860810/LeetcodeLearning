# 39. Combination Sum
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.



 

Example 1:

```
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
```
Example 2:
```
Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
```
Example 3:
```
Input: candidates = [2], target = 1
Output: []
```
Example 4:
```
Input: candidates = [1], target = 1
Output: [[1]]
```

Example 5:
```
Input: candidates = [1], target = 2
Output: [[1,1]]
```

Constraints:

* 1 <= candidates.length <= 30
* 1 <= candidates[i] <= 200
* All elements of candidates are distinct.
* 1 <= target <= 500

## solution1
這題我選擇使用DFS，原因在於透過遞迴可以去考慮每一個數字是否要被選擇。
若是我選擇了該數字，target-num 就會新的 target，那麼我可將新的 target在丟到function中去找出新的 target可以有什麼其他的組合。
1. if target < 0
不能加入這個數字因為已經超過 target
2. if target ==0
可加入這個數字，且這個數字剛好滿足了組成taget的目標
3. if taget > 0
可以加入這個數字但是還要在找其他數字近來填補剩餘的位置
