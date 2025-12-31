class Solution {
  public:
    
    int getsize(Node* h1)
    {
        int cnt=0;
        while(h1)
        {
            h1=h1->next;
            cnt++;
        }
        return cnt;
    }
    
    
    int helper(Node* h1,Node* h2)
    {
        if(!h1)return 0;
        int c1=h1->data,c2=h2->data;
        int sum=c1+c2+helper(h1->next,h2->next);
        h1->data=sum%10;
        int carry=sum/10;
        return carry;
    }
  
    Node* addTwoLists(Node* h1, Node* h2) 
    {
        // EQUALIZE Both linkedlists
        int c1=getsize(h1);
        int c2=getsize(h2);
        if(c1!=c2)
        {
            int diff=abs(c1-c2);
            Node* nh=NULL;
            Node* ch=NULL;
            while(diff--)
            {
                if(!ch)
                {
                    ch=new Node(0);
                    nh=ch;
                }
                else
                {
                    ch->next=new Node(0);
                    ch=ch->next;
                }
            }
            if(c1>c2)
            {
                ch->next=h2;
                h2=nh;
            }
            else 
            {
                ch->next=h1;
                h1=nh;
            }
        }
        

        // CARRY CAN BE -  1 or 0
        int cr=helper(h1,h2);
        if(cr)
        {
            Node* tp=new Node(cr);
            tp->next=h1;
            h1=tp;
        }
        while(h1 && h1->data==0)h1=h1->next;
        if(!h1)h1=new Node(0);
        return h1;
    }
};
