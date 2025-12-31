// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(1)

class Solution {
  public:
    
    Node* left; 
    bool helper(Node* right)
    {
        if(!right)return 1;
        bool b=helper(right->next);
        if(b==0)return 0;
        
        if(left->data != right->data)return 0;
        left=left->next;
        return 1;
    }
  
    bool isPalindrome(Node *head) 
    {
        left=head;
        return helper(head);
    }
};

// -----------------------------------------------------------------------------------------------------------------------------------------
// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(N)

class Solution {
  public:
        
    bool helper(Node* head,deque<int>&q1)
    {
        if(!head)return 1;
        q1.push_back(head->data);
        bool b=helper(head->next,q1);
        if(b==0)return 0;
        
        // b == 1
        if(q1.empty())return 1;
        else if(q1.back()!=q1.front())return 0;
        else 
        {
            q1.pop_back();
            if(!q1.empty())q1.pop_front();
            return 1;
        }
        return 0;
    }
  
    bool isPalindrome(Node *head) 
    {
        deque<int>q1;
        return helper(head,q1);
    }
};
