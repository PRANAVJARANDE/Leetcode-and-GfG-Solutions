/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    ListNode* temp;
    int helper(ListNode* head)
    {
        if(!head)return INT_MIN;
        int ans=helper(head->next);
        ans=max(ans,head->val+temp->val);
        temp=temp->next;
        return ans;
    }

    int pairSum(ListNode* head) 
    {
        temp=head;
        return helper(head); 
    }
};
