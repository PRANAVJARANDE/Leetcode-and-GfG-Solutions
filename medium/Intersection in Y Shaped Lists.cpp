/*
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    
    int getsize(Node* h)
    {
        int cnt=0;
        while(h)
        {
            cnt++;
            h=h->next;
        }
        return cnt;
    }
        
    Node* intersectPoint(Node* head1, Node* head2) 
    {
        int c1=getsize(head1);
        int c2=getsize(head2);
        
        int diff=abs(c1-c2);
        if(diff!=0)
        {
            Node* inc;
            if(c1>c2)
            {
                while(diff--)
                {
                    head1=head1->next;
                }
            }
            else 
            {
                while(diff--)
                {
                    head2=head2->next;
                }
            }
        }
        
        while(head1!=head2)
        {
            head1=head1->next;
            head2=head2->next;
        }
        return head1;
        
        
    }
};
