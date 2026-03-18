/*
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
        
    map<int,int>m;
    vector<int> topView(Node *root) 
    {
        queue<pair<Node*,int>>q1;
        q1.push({root,0});
        
        while(!q1.empty())
        {
            auto in=q1.front();
            q1.pop();
            if(m.find(in.second)==m.end())m[in.second]=(in.first)->data;
            if((in.first)->left)q1.push({(in.first)->left,in.second-1});
            if((in.first)->right)q1.push({(in.first)->right,in.second+1});
        }
        vector<int>ans;
        for(auto x:m)ans.push_back(x.second);
        return ans;
    }
};
