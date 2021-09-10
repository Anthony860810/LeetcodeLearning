# 98. Validate Binary Search Tree

Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A **valid BST** is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:
![](https://i.imgur.com/aljerA4.png)

```
Input: root = [2,1,3]
Output: true
```
Example 2:
![](https://i.imgur.com/e4QialP.png)

```
Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
```



Constraints:

* The number of nodes in the tree is in the range [1, 104].
* -231 <= Node.val <= 231 - 1

## solution1
在樹狀結構中進行搜尋多半是DFS或是BFS的問題，而在這題我嘗試使用DFS，BST有幾項特點，左子樹皆小於 root，而右子樹皆大於 root，因此我需要紀錄當前位置是否有滿足 maximum 和 minimum的條件，若是沒滿足的話，代表他放錯位置。