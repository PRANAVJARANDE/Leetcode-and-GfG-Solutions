/* Structure of binary tree node
class Node{
public:
    int data;
    Node* left, right;
    Node(int item)
    {
        data = item;
        left = nullptr;
        right = nullptr;
    }
}
*/
class Solution {
  public:
    
    map<int,int>m;
    void helper(Node* root,int line)
    {
        if(!root)return;
        m[line]+=root->data;
        helper(root->left,line-1);
        helper(root->right,line+1);
    }
  
    vector<int> verticalSum(Node* root) 
    {
        helper(root,0);
        vector<int>v1;
        for(auto x:m)v1.push_back(x.second);
        return v1;
    }
};
