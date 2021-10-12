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

    set<long long> addresses;
    bool is_circle = true;

public:
    ListNode *detectCycle(ListNode *head) {

        // early return for side cases
        if(head == NULL) {
            return NULL;
        }
        
        // main 
        long long this_address = (long long)(head);
        cout << this_address << endl; 
        
        if( addresses.find(this_address) == addresses.end() ) {
            addresses.insert(this_address);
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
