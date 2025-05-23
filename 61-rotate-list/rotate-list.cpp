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
    ListNode* newlast(ListNode* head,int k){
        int count=1;
        ListNode* temp=head;
        while(temp!=nullptr){
            if(count==k) return temp;
            count++;
            temp=temp->next;
        }
        return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || k==0) return head;
        ListNode* tail=head;
        int len=1;
        while(tail->next!=nullptr){
            tail=tail->next;
            len++;
        }
        if(k%len==0) return head;
        k=k%len;
        tail->next=head;
        ListNode* newlastnode=newlast(head,len-k);
        head=newlastnode->next;
        newlastnode->next=nullptr;
        return head;
    }
};