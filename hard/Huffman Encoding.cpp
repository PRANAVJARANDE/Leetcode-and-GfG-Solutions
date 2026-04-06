class Solution {
  public:
    
    
    class Node{
      public:
        
        Node* left;
        Node* right;
        Node()
        {
            left=NULL;
            right=NULL;
        }
    };
    
    vector<string>ans;
    void generate(Node* root,string &s)
    {
        if(!root->left && !root->right)
        {
            ans.push_back(s);
            return;
        }
        s.push_back('0');
        generate(root->left,s);
        s.pop_back();
        
        s.push_back('1');
        generate(root->right,s);
        s.pop_back();
    }
  
    vector<string> huffmanCodes(string &s, vector<int> f) 
    {
        int n=s.size();
        if(n==1)return {"0"};
        
        
        
        priority_queue<pair<pair<int,int>,Node*>,vector<pair<pair<int,int>,Node*>>,greater<pair<pair<int,int>,Node*>>>q1;
        
        // {{ freq  , index }, Node }
        
        for(int i=0;i<n;i++)q1.push({{f[i],i},new Node()});
        
        while(q1.size()>=2)
        {
            auto p1=q1.top();
            q1.pop();
            auto p2=q1.top();
            q1.pop();
            Node* nv=new Node();
            nv->left=p1.second;
            nv->right=p2.second;
            q1.push({{p1.first.first+p2.first.first,min(p1.first.second,p2.first.second)},nv});
        }
        
        string ts;
        generate((q1.top()).second,ts);
        return ans;
        
        
    }
};
