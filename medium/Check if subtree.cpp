/*
Definition for Node
struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    
    bool helper(Node* pt,Node* root2)
    {
        if(!pt && !root2)return 1;
        if(!pt)return 0;
        if(!root2)return 0;
        
        if(pt->data != root2->data)return 0;
        
        auto l=helper(pt->left,root2->left);
        if(l==0)return 0;
        auto r=helper(pt->right,root2->right);
        if(r==0)return 0;
        
        return 1;
    }
    
    bool isSubTree(Node *root1, Node *root2) 
    {
        if(!root1)return 0;
        if(root1->data==root2->data)
        {
            bool f=helper(root1,root2);
            if(f)return 1;
        }
        auto l=isSubTree(root1->left,root2);
        if(l)return l;
        auto r=isSubTree(root1->right,root2);
        if(r)return r;
        return 0;
    }
};
