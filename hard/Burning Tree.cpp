/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    
    map<int,int>h;
    int helper(Node* root)
    {
        if(!root)return 0;
        int lh=helper(root->left);
        int rh=helper(root->right);
        return h[root->data]=1+max(lh,rh);
    }
    
    int getans(Node*root,int ext,int tar)
    {
        if(!root)return -1;
        if(root->data==tar)
        {
            return max(h[root->data],ext)-1;
        }
        
        int lpass=ext+1;
        if(root->right)lpass=max(lpass,h[root->right->data]+2);
        
        int rpass=ext+1;
        if(root->left)rpass=max(rpass,h[root->left->data]+2);
        
        int lh=getans(root->left,lpass,tar);
        if(lh!=-1)return lh;
        int rh=getans(root->right,rpass,tar);
        if(rh!=-1)return rh;
        return -1;
    }
  
    int minTime(Node* root, int target) 
    {
        helper(root);
        return getans(root,1,target);
    }
};
