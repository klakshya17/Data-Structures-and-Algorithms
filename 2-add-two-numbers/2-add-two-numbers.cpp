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
    ListNode* fun(ListNode* a,ListNode* b){
        int carry=0;
        ListNode* head = NULL,*temp;
        while(a!=nullptr && b!=nullptr){
            ListNode* node = new ListNode;
            if(head==NULL){
                head = node;
                temp = node;}
            else {
                temp->next = node;
                temp = temp->next; }
            int num = a->val + b->val + carry;
            if(num<10){
                carry = 0;
                temp->val = num;
            }
            else{
                carry = 1;
                temp->val = num%10;
            }
            
            a = a->next;
            b = b->next;
        }
        while(a!=nullptr){
            ListNode* node = new ListNode;
            
            temp->next = node;
            temp = temp->next; 
            
            int num = a->val + carry;
            if(num<10){
                carry = 0;
                temp->val = num;
            }
            else{
                carry = 1;
                temp->val = num%10;
            }
            
            a = a->next;

        }
        while(b!=nullptr){
            ListNode* node = new ListNode;
            
            temp->next = node;
            temp = temp->next; 
            
            int num = b->val + carry;
            if(num<10){
                carry = 0;
                temp->val = num;
            }
            else{
                carry = 1;
                temp->val = num%10;
            }
            
            b = b->next;
        }
        if(carry){
            ListNode* node = new ListNode(1);
            temp->next= node;
        }
        return head;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
     if(l1==nullptr && l2==nullptr)
         return nullptr;
     if(l1==nullptr)
         return l2;
     if(l2==nullptr)
         return l1;
     return fun(l1,l2);   
    }
};