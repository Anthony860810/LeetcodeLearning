# 1 Two Sum Solution
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.


Example 1:
```
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Output: Because nums[0] + nums[1] == 9, we return [0, 1].
```
Example 2:
```
Input: nums = [3,2,4], target = 6
Output: [1,2]
```
Example 3:
```
Input: nums = [3,3], target = 6
Output: [0,1]
```
Constraints:

* 2 <= nums.length <= 103
* -109 <= nums[i] <= 109
* -109 <= target <= 109
* Only one valid answer exists.

## Tools
### map
1. 資料結構: 紅黑樹
2. search: O(logN)
``` C++
/*Initialzie Map*/
map<int, int> Map;
```

``` C++
/*Searches the container for elements with a key equivalent 
to k and returns the number of matches.*/
int num = map.count(k)
```

``` C++
/*Insert element into map*/
 Map.insert(pair<int,int>(nums[idx],idx))
```

### unordered_map
用法同map
1. 資料結構: hash_table
2. search: O(1)

## solution1
直接兩兩比對去找出是否有可以配對的組合
### 複雜度
時間複雜度： O(n^2)
空間複雜度: O(1)
## solution2
由於這是一個 two sum 的問題，那麼可以看成可以組成target的兩個數為一組互補數。
```
target = num + complement
complement = target - num
```
藉由這個想法，我們可以將每個已查詢過的element儲存，若是在我們的容器中有找到其 complement就加入到ans中，若是尚未發現 element 的 complement 有在容器中的話就將他存到容器中。容器我選擇使用map 或是 unodered_map，因為其查詢速度較快。
### 複雜度
時間複雜度: O(n)
空間複雜度: O(n)