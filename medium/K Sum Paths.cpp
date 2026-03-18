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
    
    void build(Node* root,int sum)
    {
        if(!root)return;
        root->data+=sum;
        build(root->left,root->data);
        build(root->right,root->data);
    }
    
    map<int,int>m;
    int helper(Node* root,int k)
    {
        if(!root)return 0;
        int cs=root->data;
        int res=m[cs-k];
        m[cs]++;
        res+=helper(root->left,k)+helper(root->right,k);
        m[cs]--;
        return res;
    }
  
    int countAllPaths(Node *root, int k) 
    {
        build(root,0);
        m[0]++;
        return helper(root,k);
    }
};
