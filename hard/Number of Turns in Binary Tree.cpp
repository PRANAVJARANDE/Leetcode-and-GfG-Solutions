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
}; */
#define ll long long
class Solution {
  public:
    
    // pv=0 left
    // pv=1 right
    ll helper(Node* root,int pv,int v)
    {
        if(!root)return INT_MAX;
        if(root->data==v)return 0;
        ll op1=helper(root->left,0,v);
        ll op2=helper(root->right,1,v);
        if(pv==0)op2++;
        else if(pv==1)op1++;
        return min(op1,op2);
    }
    
    bool getpath(Node* root,int p,vector<Node*>&p1)
    {
        if(!root)return 0;
        p1.push_back(root);
        if(root->data==p)return 1;
        bool b1=getpath(root->left,p,p1);
        if(b1)return 1;
        bool b2=getpath(root->right,p,p1);
        if(b2)return 1;
        p1.pop_back();
        return 0;
    }
    
    int numberOfTurns(Node* root, int p, int q) 
    {
        vector<Node*>v1,v2;
        getpath(root,p,v1);
        getpath(root,q,v2);
        
        reverse(v1.begin(),v1.end());
        reverse(v2.begin(),v2.end());
        
        Node* anc;
        while(!v1.empty() && !v2.empty() && v1.back()==v2.back())
        {
            anc=v1.back();
            v1.pop_back();
            v2.pop_back();
        }
        
        if(v1.empty())
        {
            int ans=helper(anc,-1,q);
            return ans==0?-1:ans;
        }
    
        if(v2.empty())
        {
            int ans=helper(anc,-1,p);
            return ans==0?-1:ans;
        }
        
        int ans=1;
        ans+=helper(anc,-1,p);
        ans+=helper(anc,-1,q);
        return ans;
    }
};
