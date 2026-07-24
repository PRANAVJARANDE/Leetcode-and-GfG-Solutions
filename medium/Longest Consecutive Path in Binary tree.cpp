/* Structure of Binary Tree Node
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
  
    // maxi in subtree , max considering current node
    
    pair<int,int> helper(Node* root)
    {
        if(!root)return {0,0};
        auto l=helper(root->left);
        auto r=helper(root->right);
        
        int lcurr=1,rcurr=1;
        if(root->left && root->data+1==root->left->data)lcurr+=l.second;
        if(root->right && root->data+1==root->right->data)rcurr+=r.second;
        int curr=max(lcurr,rcurr);
        
        int subtree_max=max(l.first,max(r.first,curr));
        return {subtree_max,curr};
    }
  
    int longestConsecutive(Node* root) 
    {
        auto temp=helper(root);
        if(temp.first==1)return -1;
        return temp.first;
        
    }
};















