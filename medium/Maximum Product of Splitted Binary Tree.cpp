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

    long long build(TreeNode* root)
    {
        if(!root)return 0;
        long long ans=root->val+build(root->left)+build(root->right);
        root->val=ans;
        return ans;
    }

    long long sum;
    const long long MOD=1e9+7;
    long long helper(TreeNode* root)
    {
        if(!root)return 0;
        long long ans=(root->val)*(sum-(root->val));
        ans=max(ans,helper(root->right));
        ans=max(ans,helper(root->left));
        return ans;
    }

    int maxProduct(TreeNode* root) 
    {
        sum=build(root);   
        long long ans=helper(root)%MOD;
        return ans;
    }
};
