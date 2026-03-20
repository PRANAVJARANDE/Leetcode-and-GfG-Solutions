/* BST Node
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    
    Node* getpre(Node* root,int key)
    {
        if(!root)return NULL;
        int rv=root->data;
        if(rv>=key)return getpre(root->left,key);
        else
        {
            auto res=getpre(root->right,key);
            if(!res)res=root;
            return res;
        }
    }
    
    Node* getsuc(Node* root,int key)
    {
        if(!root)return NULL;
        int rv=root->data;
        if(rv<=key)return getsuc(root->right,key);
        else
        {
            auto res=getsuc(root->left,key);
            if(!res)res=root;
            return res;
        }
    }
    
    vector<Node*> findPreSuc(Node* root, int key) 
    {
        vector<Node*>ans(2,NULL);
        ans[0]=getpre(root,key);
        ans[1]=getsuc(root,key);
        return ans;
    }
};
