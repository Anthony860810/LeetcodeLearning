# 19. Remove Nth Node From End of List
Given the head of a linked list, remove the nth node from the end of the list and return its head.

Follow up: Could you do this in one pass?

 

Example 1:

![](https://i.imgur.com/yoDi7KH.png)

```
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
```
Example 2:
```
Input: head = [1], n = 1
Output: []
```
Example 3:
```
Input: head = [1,2], n = 1
Output: [1]
```


Constraints:

* The number of nodes in the list is sz.
* 1 <= sz <= 30
* 0 <= Node.val <= 100
* 1 <= n <= sz

## solution1
在一開始我先計算了有多少個element在這串Linklist中，接著計算 n 實際為從頭數來第幾個 element，最後將他移除。