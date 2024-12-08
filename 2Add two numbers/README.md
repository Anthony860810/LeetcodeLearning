# 2. Add Two Numbers
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Example 2:
Input: l1 = [0], l2 = [0]
Output: [0]

Example 3:
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.

## Tools
### Linked list
1. 這題可以複習如何intial一個新的struct 並用pointer指向他
2. 注意linked list traverse

# solution1
此題重點在於如何travese linked list 並且要注意是否有進位跟其中一個linked list較短的問題。
由於需要定錨一個起點，所以當建立出第一個node的時候會先用start做定錨，而cur則會持續跟著新創建的node往前走。
### 複雜度
時間複雜度: O(n)
空間複雜度: O(n)