/* Structure for Tree Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    
    int helper(Node* root)
    {
        if(!root)return 0;
        int rval=root->data;
        int val=helper(root->left)+helper(root->right);
        root->data=val;
        return rval+val;
    }
  
    void toSumTree(Node *root) 
    {
        helper(root);  
    }
};
