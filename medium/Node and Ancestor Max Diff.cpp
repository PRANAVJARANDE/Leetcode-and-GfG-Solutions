/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    
    int helper(Node* root,int anc)
    {
        if(!root)return INT_MIN;
        int ans=INT_MIN;
        if(anc!=INT_MIN)ans=anc-root->data;
        int la=helper(root->left,max(anc,root->data));
        int ra=helper(root->right,max(anc,root->data));
        return max(ans,max(la,ra));
    }
  
  
    int maxDiff(Node* root) 
    {
        return helper(root,INT_MIN);
    }
};
