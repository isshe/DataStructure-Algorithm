题目地址：https://leetcode.com/problems/flatten-binary-tree-to-linked-list/      
题目描述：给一个二叉树，把二叉树转为链表，存在右子树。（链表的顺序为二叉树先序遍历的结果）    
思路1：   
1. 左子树的最右节点转为链表后，会接右子树。  
2. 故每次都把一个左子树的最右节点连接到右子树，即可。具体见代码。  