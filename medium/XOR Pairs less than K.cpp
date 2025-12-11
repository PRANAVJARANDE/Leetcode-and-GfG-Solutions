class Solution {
  public:
    
    class Node
    {
        public:
        int cnt;
        vector<Node*>next;
        Node()
        {
            cnt=0;
            next=vector<Node*>(2,NULL);
        }
    };
    
    
    int count(Node* root,int n,int k)
    {
        Node* temp=root;
        int ans=0;
        for(int i=16;i>=0;i--)
        {
            bool nc=(n & (1<<i));
            bool kc=(k & (1<<i));
            if(kc==0)
            {
                int yc=nc;
                if(!temp->next[yc])break;
                temp=temp->next[yc];
            }
            else
            {
                int yc=nc;
                if(temp->next[yc])ans+=temp->next[yc]->cnt;
                if(!temp->next[1-yc])break;
                temp=temp->next[1-yc];
            }
        }
        
        temp=root;
        for(int i=16;i>=0;i--)
        {
            bool nc=(n & (1<<i));
            if(!temp->next[nc])temp->next[nc]=new Node();
            temp=temp->next[nc];
            temp->cnt+=1;
        }
        return ans;
    }
  
    int cntPairs(vector<int>& a, int k) 
    {
        Node* root=new Node();
        int ans=0;
        for(auto x:a)
        {
            ans+=count(root,x,k);
        }
        return ans;
    }
};
