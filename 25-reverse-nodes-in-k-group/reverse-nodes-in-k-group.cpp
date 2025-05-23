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
    ListNode* reverse(ListNode* head){
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode* newhead=reverse(head->next);
        ListNode* front=head->next;
        front->next=head;
        head->next=nullptr;
        return newhead;
    }

    ListNode* kthnode(ListNode* temp,int k){
        k=k-1;
        while(temp!=nullptr && k>0){
            k--;
            temp=temp->next;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prevnode=nullptr;
        ListNode* nextnode;
        while(temp!=nullptr){
            ListNode* kth=kthnode(temp,k);
            if(kth==nullptr){
                if(prevnode) prevnode->next=temp;
                break;
            }
            nextnode=kth->next;
            kth->next=nullptr;
            reverse(temp);
            if(temp==head){
                head=kth;
            }
            else{
                prevnode->next=kth;
            }
            prevnode=temp;
            temp=nextnode;
        }
        return head;
    }
};