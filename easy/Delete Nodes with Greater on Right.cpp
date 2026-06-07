/* Structure of a Linked List node
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    
    int mx;
    
    Node* helper(Node* head)
    {
        if(!head)return NULL;
        Node* nx=compute(head->next);
        if(mx>head->data)return nx;
        mx=max(mx,head->data);
        head->next=nx;
        return head;
    }
    
    Node* compute(Node *head) 
    {
        mx=INT_MIN;
        return helper(head);
    }
};
