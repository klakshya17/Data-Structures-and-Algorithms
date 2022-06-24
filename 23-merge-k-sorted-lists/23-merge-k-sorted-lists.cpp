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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<k;i++){
            if(lists[i]!=NULL){
            pq.push(make_pair(lists[i]->val,i));
            lists[i] = lists[i]->next;}
        }
        if(pq.empty())
            return NULL;
        ListNode* head = new ListNode(pq.top().first);
        if(lists[pq.top().second]!=NULL){
                // cout<<lists[pq.top().second]->val<<" ";
                pq.push(make_pair(lists[pq.top().second]->val,pq.top().second));
                lists[pq.top().second] = lists[pq.top().second]->next;
            }        
        pq.pop();
        ListNode* node = head;
        while(!pq.empty()){
            // cout<<pq.top().first;
            ListNode* n = new ListNode(pq.top().first);
            node->next = n;
            node = n;
            
            //to find the next element to push in pq
            if(lists[pq.top().second]!=NULL){
                // cout<<lists[pq.top().second]->val<<" ";
                pq.push(make_pair(lists[pq.top().second]->val,pq.top().second));
                lists[pq.top().second] = lists[pq.top().second]->next;
            }
            // cout<<pq.size()<<" ";
            pq.pop();
        }
        return head;
    }
};