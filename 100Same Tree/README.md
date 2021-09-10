# 100. Same Tree

Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.
 

Example 1:
![](https://i.imgur.com/Gd0OYSf.png)


```
Input: p = [1,2,3], q = [1,2,3]
Output: true
```
Example 2:
![](https://i.imgur.com/DDiS66u.png)


```
Input: p = [1,2], q = [1,null,2]
Output: false
```

Example 3:
![](https://i.imgur.com/SpV4mLD.png)
```
Input: p = [1,2,1], q = [1,1,2]
Output: false
```

Constraints:

* The number of nodes in both trees is in the range [0, 100].
* -104 <= Node.val <= 104

## solution1
樹狀結構第一個就會想到使用DFS和BFS，而在這我使用DFS來解題，而如何判定是相同的樹，就只要看當前位置，和他的左右子樹是否都是相同即可判定，因此判定當前 node 的 val 相同後，就去看左右子樹即可。