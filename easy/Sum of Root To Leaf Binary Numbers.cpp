/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int helper(TreeNode* root,int val)
    {
        if(!root)return 0;
        if(!root->left && !root->right)return (val*2)+root->val;
        int nval=val*2;
        if(root->val)nval++;
        int ans=0;
        if(root->left)ans+=helper(root->left,nval);
        if(root->right)ans+=helper(root->right,nval);
        return ans;
    }

    int sumRootToLeaf(TreeNode* root) {
        return helper(root,0);
    }
};
