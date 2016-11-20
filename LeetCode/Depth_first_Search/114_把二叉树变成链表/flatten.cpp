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
    void flatten(TreeNode* root) {
        TreeNode *saveright = NULL;
        
        while(root != NULL)
        {
            saveright = root->left;
            if (saveright != NULL)
            {
                while(saveright->right != NULL)
                {
                    saveright = saveright->right;
                }
                
                saveright->right = root->right;
                root->right = root->left;
                root->left = NULL;
            }

            root = root->right;
        }
        
    }
};