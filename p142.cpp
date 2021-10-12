/* idea
    recursive function call 
*/
    
/* result 
    Runtime: 41 ms, faster than 5.03% of C++ online submissions for Linked List Cycle II.
    Memory Usage: 12.1 MB, less than 6.42% of C++ online submissions for Linked List Cycle II.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


class Solution {
public:
    ListNode * start_address = NULL;

    set<ListNode *> addresses;
    bool is_circle = true;

public:
    ListNode *detectCycle(ListNode *head) {

        // early return for side cases
        if(head == NULL) {
            return NULL;
        }
        
        // main         
        if( addresses.find(head) == addresses.end() ) {
            addresses.insert(head);
        } else {
            start_address = head;
        }
        
        if(head->next != NULL) {
            if(start_address != NULL) {
               // do nothing  
            } else {
                detectCycle(head->next);                
            }
        } else {
            is_circle = false;
        }
        
        if( !is_circle ) {
            return NULL;
        } else {
            return start_address;            
        }
    }
};
