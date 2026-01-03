/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class Solution {
  public:
    Node *flatten(Node *root) 
    {
        priority_queue<pair<int,Node*>,vector<pair<int,Node*>>,greater<pair<int,Node*>>>q1;
        while(root)
        {
            q1.push({root->data,root});
            root=root->next;
        }
        
        Node* head=NULL;
        Node* prev=NULL;
        
        while(!q1.empty())
        {
            auto in=q1.top().second;
            q1.pop();
            if(!head)head=in;
            else prev->bottom=in;
            prev=in;
            if(in->bottom)q1.push({in->bottom->data,in->bottom});
        }
        
        return head;
    }
};
