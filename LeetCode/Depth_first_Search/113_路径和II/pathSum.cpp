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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> path;
        
        recursive(root, sum, 0, res, path);
        
        return res;
    }
    
    void recursive(TreeNode *root, int sum, int cursum, vector<vector<int>> &res, vector<int> &path)
    {
        if (root == NULL)
        {
            return ;
        }
        if (root->left == NULL && root->right == NULL)
        {
            cursum += root->val;
            if (cursum == sum)
            {
                path.push_back(root->val);
                res.push_back(path);
                path.pop_back();
            }
            
            return ;
        }
        
        path.push_back(root->val);
        if (root->left != NULL)
        {
            recursive(root->left, sum, cursum + root->val, res, path);
        }
        if (root->right != NULL)
        {
            recursive(root->right, sum, cursum + root->val, res, path);
        }
        path.pop_back();
    }
};