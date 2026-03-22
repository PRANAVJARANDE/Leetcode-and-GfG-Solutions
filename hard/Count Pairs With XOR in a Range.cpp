class Solution {
public:

    const int mb=20;

    class Node{
        public:
            vector<Node*>next;
            int sum;
        Node()
        {
            sum=0;
            next=vector<Node*>(2,NULL);
        }
    };

    void insert(int x,Node* root)
    {
        Node* temp=root;
        for(int i=mb;i>=0;i--)
        {
            int b=0;
            if(x & (1<<i))b=1;
            if(!temp->next[b])temp->next[b]=new Node();
            temp=temp->next[b];
            temp->sum++;
        }
    }

    int countPairs(vector<int>& nums, int low, int high) 
    {
        Node* root1=new Node();
        high++;

        int ans=0;
        for(auto x:nums)
        {
            Node* temp=root1;
            for(int i=mb;i>=0;i--)
            {
                if(!temp)break;
                if(high & (1<<i))
                {
                    if(x & (1<<i))
                    {
                        if(temp->next[1])ans+=temp->next[1]->sum;
                        temp=temp->next[0];
                    }
                    else 
                    {
                        if(temp->next[0])ans+=temp->next[0]->sum;
                        temp=temp->next[1];
                    }
                }
                else
                {
                    if(x & (1<<i))temp=temp->next[1];
                    else temp=temp->next[0];
                }   
            }
            insert(x,root1);
        }

        Node* root2=new Node();
        for(auto x:nums)
        {
            Node* temp=root2;
            for(int i=mb;i>=0;i--)
            {
                if(!temp)break;
                if(low & (1<<i))
                {
                    if(x & (1<<i))
                    {
                        if(temp->next[1])ans-=temp->next[1]->sum;
                        temp=temp->next[0];
                    }
                    else 
                    {
                        if(temp->next[0])ans-=temp->next[0]->sum;
                        temp=temp->next[1];
                    }
                }
                else
                {
                    if(x & (1<<i))temp=temp->next[1];
                    else temp=temp->next[0];
                }   
            }
            insert(x,root2);
        }
        return ans;
    }
};
