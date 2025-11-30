class Solution {
  public:
    
    class Node{
        public:
        vector<Node*>next;
        Node()
        {
            next=vector<Node*>(26,NULL);
        }
    };
  
    int countSubs(string& s) 
    {
        int ans=0;    
        Node* root=new Node();
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            Node* temp=root;
            for(int j=i;j<n;j++)
            {
                int ch=s[j]-'a';
                if(!temp->next[ch])
                {
                    temp->next[ch]=new Node();
                    ans++;
                }
                temp=temp->next[ch];
            }
        }
        return ans;
    }
};
