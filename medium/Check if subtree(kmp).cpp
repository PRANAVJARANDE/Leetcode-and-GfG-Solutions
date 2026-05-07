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
    
    vector<int> getlps(string&s)
    {
        int n=s.size();
        vector<int>lps(n,-1);
        
        int in=-1;
        for(int i=1;i<n;i++)
        {
            while(in!=-1 && s[in+1]!=s[i])
            {
                in=lps[in];
            }
            if(s[in+1]==s[i])in++;
            lps[i]=in;
        }
        return lps;
    }
    
    bool matching(string&s,string&t)
    {
        vector<int>lps=getlps(t);
        int n=s.size();
        int m=t.size();
        
        int in=-1;
        for(int i=0;i<n;i++)
        {
            while(in!=-1 && s[i]!=t[in+1])
            {
                in=lps[in];
            }
            if(s[i]==t[in+1])in++;
            if(in==m-1)return 1;
        }
        return 0;
    }

    void serialize(Node* root,string&s)
    {
        if(!root)
        {
            s=s+"# ";
            return;
        }
        s=s+to_string(root->data)+" ";
        serialize(root->left,s);
        serialize(root->right,s);
    }
    
    bool isSubTree(Node *root1, Node *root2) 
    {
        string s1,s2;
        serialize(root1,s1);
        serialize(root2,s2);
        
        return matching(s1,s2);
    }
};
