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
    ListNode* reverse(ListNode* head,int k){
        
        ListNode* curr= head,*prev=NULL,*next;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            
        }
        return prev;
    }
    ListNode* findk(ListNode* temp, int k){
        ListNode* node=temp;
        int count=1;
        while(node!=NULL && count<k){
            count++;
            node=node->next;
        }
        if (count < k) {
            return temp; // Not enough nodes to reverse
        }
        
        return node;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp= head,*prev=NULL;
        while(temp!=NULL){
            ListNode*kthnode=findk(temp,k);
            if(kthnode==NULL){
            if(prev){
                prev->next=temp;
            }
                break;

            }
            ListNode* nextno=kthnode->next;
            kthnode->next=NULL;
            reverse(temp,k);
            if(temp==head){
                head=kthnode;

            }
            else{
                prev->next=kthnode;
            }
            prev=temp;
            temp=nextno;
        }
        return head;
        
           
    }
};