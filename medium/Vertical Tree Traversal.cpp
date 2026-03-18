/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<vector<int>> verticalOrder(Node *root) 
    {
        queue<pair<Node*,int>>q1;
        q1.push({root,0});
        map<int,vector<int>>m;
        while(!q1.empty())
        {
            auto node=q1.front().first;
            int val=q1.front().second;
            q1.pop();
            m[val].push_back(node->data);
            if(node->left)q1.push({node->left,val-1});
            if(node->right)q1.push({node->right,val+1});
        }
        vector<vector<int>>ans;
        for(auto x:m)ans.push_back(x.second);
        return ans;
    }
};
