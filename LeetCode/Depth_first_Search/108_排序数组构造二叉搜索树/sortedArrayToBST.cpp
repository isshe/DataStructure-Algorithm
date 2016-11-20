/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode *root = NULL;
        
        root = transCore(nums, 0, nums.size()-1);
        
        return root;
    }
    
    TreeNode *transCore(vector<int> &nums, int start, int end)
    {
        if (start > end)
            return NULL;
        int mid = start + (end - start) / 2;
        
        TreeNode *newNode = new TreeNode(nums[mid]);
        
        newNode->left = transCore(nums, start, mid-1);
        newNode->right = transCore(nums, mid+1, end);
        
        return newNode;
    }
    
    
};