class Solution {
  public:
    
    class Node{
        public:
            vector<Node*>next;
            Node()
            {
                next=vector<Node*>(2,NULL);
            }
    };
    
    void insert_NUMBER(Node* root,int num)
    {
        Node* temp=root;
        for(int i=30;i>=0;i--)
        {
            if(num & (1<<i))
            {
                if(!temp->next[1])temp->next[1]=new Node();
                temp=temp->next[1];
            }
            else
            {
                if(!temp->next[0])temp->next[0]=new Node();
                temp=temp->next[0];
            }
        }
    }
  
    int maxSubarrayXOR(int N, int arr[]) {
        Node* root=new Node();
        insert_NUMBER(root,0);
        int ans=0;
        int xsum=0;
        for(int i=0;i<N;i++)
        {
            int x=arr[i];
            xsum^=x;
            
            int res=0;
            Node* temp=root;
            for(int i=30;i>=0;i--)
            {
                if(xsum & (1<<i))
                {
                    if(temp->next[0])
                    {
                        res=res | (1<<i);
                        temp=temp->next[0];
                    }
                    else
                    {
                        temp=temp->next[1];
                    }
                }
                else
                {
                    if(temp->next[1])
                    {
                        res=res | (1<<i);
                        temp=temp->next[1];
                    }
                    else
                    {
                        temp=temp->next[0];
                    }
                }
            }
            ans=max(ans,res);
            insert_NUMBER(root,xsum);
        }
        return ans;
    }
};
