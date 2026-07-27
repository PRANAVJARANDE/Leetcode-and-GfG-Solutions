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
    
    map<int,int>m1,m2;
    
    Node* helper(int i1,int i2,int sz,vector<int>&a,vector<int>&b)
    {
        if(sz==0)return NULL;
        if(sz==1)return new Node(a[i1]);
        Node* root=new Node(a[i1]);
        
        int in=m2[a[i1+1]];
        int rsz=in-i2-1;
        int lsz=sz-rsz-1;
        
        root->left=helper(i1+1,in,lsz,a,b);
        root->right=helper(i1+lsz+1,i2+1,rsz,a,b);
        return root;
    }
  
    Node *constructBinaryTree(vector<int> &a, vector<int> &b) 
    {
        int n=a.size();
        m1.clear();
        m2.clear();
        
        for(int i=0;i<n;i++)
        {
            m1[a[i]]=i;
            m2[b[i]]=i;
        }
        return helper(0,0,n,a,b);
    }
};
