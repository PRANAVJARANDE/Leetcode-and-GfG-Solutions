/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    
    // isbst ans size maxi mini
  
    vector<int> helper(Node* root)
    {
        if(!root)return {1,0,0,INT_MIN,INT_MAX};
        auto v1=helper(root->left);
        auto v2=helper(root->right);
        if(v1[0] && v2[0] && v1[3]<root->data && root->data<v2[4])return {1,v1[2]+v2[2]+1,v1[2]+v2[2]+1,max(root->data,max(v1[3],v2[3])),min(root->data,min(v1[4],v2[4]))};
        return {0,max(v1[1],v2[1]),v1[2]+v2[2]+1,max(root->data,max(v1[3],v2[3])),min(root->data,min(v1[4],v2[4]))};
    }
    
    int largestBst(Node *root) 
    {
        auto v=helper(root);
        return v[1];
    }
};
