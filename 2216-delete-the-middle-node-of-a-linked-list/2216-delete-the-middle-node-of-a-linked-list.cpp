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
    ListNode* findmid(ListNode* head){
        if(head==NULL || head->next == NULL)  return nullptr;
        ListNode *slow=head;
        ListNode* fast=head;
        fast = head->next->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
            fast=fast->next;
        }
        return slow;
    }
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* newhead=head;
        ListNode* mid= findmid(newhead);
        if(head==NULL || head->next == NULL)  return nullptr;
        cout<<mid->val;
        ListNode* curr=mid->next;
        mid->next=curr->next;
        return head;
    }
};