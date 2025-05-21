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
    ListNode* sortList(ListNode* head) {
        if(head==nullptr || head->next==nullptr ){
            return head;
        }
        ListNode* temp=head;
        vector<int> arr;
        while(temp!=nullptr){
            arr.push_back(temp->val);
            temp=temp->next;
        }
        std::sort(arr.begin(),arr.end());
        temp=head;
        int i=0;
        while(temp!=nullptr){
            temp->val=arr[i];
            i++;
            temp=temp->next;
        }
        return head;
    }
};